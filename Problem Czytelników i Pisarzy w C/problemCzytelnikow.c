	#include <stdio.h>
	
	#include <stdlib.h>
	
	#include <string.h>
	
	#include <unistd.h>
	
	#include <errno.h>
	
	#include <pthread.h>
	
	char dataBase[] = "Ala ma kota";
	char ala = 'A';
	pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
	void * reader(void * a) {
	  while (1 == 1) {
	
	    int i;
	    pthread_mutex_lock( & mutex);
	    printf("\n >>Czytelnik>> Ja czytam:  %s ......\n", dataBase);
	    sleep(70);
	    pthread_mutex_unlock( &mutex);
	  }
	}
	
	void * writer(void * a) {
	  while (1 == 1) {
	
	    pthread_mutex_lock( & mutex);
	    dataBase[0] = ++ala;
	    printf("\n >>Pisarz>> Ja pisze:  %s\n", dataBase);
	    pthread_mutex_unlock( & mutex);
	    sleep(4);
	  }
	
	}
	
	int main() {
	  pthread_t reader_;
	  pthread_t writer_;
	  int result = pthread_create( & reader_, NULL, reader, (void * ) 1);
	  if (result != 0) {
	    perror("Nie moge utworzyc watku.");
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
	
	  return 0;
	}
	
