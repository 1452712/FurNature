using System;
using System.Data.Entity;
using System.ComponentModel.DataAnnotations;

namespace FurNature.Models
{
    public class Furniture
    {
        public string Id { get; set; }
        public string Name { get; set; }
        public string Type { get; set; }
        public string Path { get; set; }
        public string Img { get; set; }
        public float Price { get; set; }
        public string Purchase_url { get; set; }
        public string Introduction { get; set; }
        
        //public class FurnitureDBContext : DbContext
        //{
        //    public DbSet<Furniture> Furnitures { get; set; }
        //}
    }
}