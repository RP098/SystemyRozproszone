using System;
using System.ComponentModel.DataAnnotations.Schema;
using System.Data.Entity;
using System.Linq;

namespace AutoLotDAL
{
    public partial class CarLot : DbContext
    {
        public CarLot()
            : base("name=CarLot")
        {
        }

        public virtual DbSet<Customer> Customer { get; set; }
        public virtual DbSet<Inventory> Inventory { get; set; }
        public virtual DbSet<Order> Order { get; set; }

        protected override void OnModelCreating(DbModelBuilder modelBuilder)
        {
            modelBuilder.Entity<Customer>()
                .Property(e => e.FirstName)
                .IsFixedLength();

            modelBuilder.Entity<Customer>()
                .Property(e => e.LastName)
                .IsFixedLength();

            modelBuilder.Entity<Customer>()
                .HasMany(e => e.Order)
                .WithRequired(e => e.Customer)
                .WillCascadeOnDelete(false);

            modelBuilder.Entity<Inventory>()
                .Property(e => e.Make)
                .IsFixedLength();

            modelBuilder.Entity<Inventory>()
                .Property(e => e.Color)
                .IsFixedLength();

            modelBuilder.Entity<Inventory>()
                .Property(e => e.CarNickName)
                .IsFixedLength();
        }
    }
}
