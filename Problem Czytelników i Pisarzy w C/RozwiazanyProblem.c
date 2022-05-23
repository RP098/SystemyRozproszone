	
	#include <stdio.h>
	
	#include <stdlib.h>
	
	#include <string.h>
	
	#include <unistd.h>
	
	#include <errno.h>
	
	#include <pthread.h>
	
	
	char dataBase[] = "Ala ma kota";
	char ala = 'A';
	typedef enum {
	  TRUE = 1, FALSE = 0
	}
	bool;
	bool writer_wait = TRUE;
	bool reader_wait = TRUE;
	pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
	int clockWriter = 8;
	int clockReader = 8;
	void * reader(void * a) {
	  clockReader = 8;
	  pthread_mutex_lock( & mutex);
	  while (1 == 1) {
	
	    if (clockReader > 0) {
	      printf("\n >>Czytelnik>> Ja czytam:  %s ....... \n", dataBase);
	      clockReader--;
	
	    } else {
	      break;
	    }
	
	    if (writer_wait == FALSE) {
	      clockReader = 8;
	
	    }
	    sleep(1);
	
	  }
	  pthread_mutex_unlock( & mutex);
	}
	
	void * writer(void * a) {
	  clockWriter = 8;
	  pthread_mutex_lock( & mutex);
	  while (1 == 1) {
	
	    if (clockWriter > 0) {
	
	      dataBase[0] = ++ala;
	      printf("\n >>Pisarz>> Ja pisze:  %s\n", dataBase);
	      clockWriter--;
	      sleep(1);
	    } else {
	      break;
	    }
	    if (reader_wait == FALSE) {
	      clockWriter = 8;
	    }
	
	  }
	  pthread_mutex_unlock( & mutex);
	}
	
	int main() {
	
	  int i = 0;
	  for (i; i < 5; i++) {
	    pthread_t reader_;
	    pthread_t writer_;
	    int result = pthread_create( & reader_, NULL, reader, (void * ) 1);
	    if (result != 0) {
	      perror("Nie moge uworzyc watku.");
	    }
	    result = pthread_create( & writer_, NULL, writer, (void * ) 1);
	    if (result != 0) {
	      perror("Nie moge utworzyc watku.");
	    }
	    void * result_;
	    if (pthread_join(reader_, & result_) == -1)
	      perror("Blad oczekiwania na zakonczenie watku t0");
	    if (pthread_join(writer_, & result_) == -1)
	      perror("Blad oczekiwania na zakonczenie watku t0");
	  }
	
	  return 0;
}



