using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data.Entity;

namespace FurNature.Models
{
    public class Photo
    {
        public string ID { get; set; }
        public string UserID { get; set; }
        public string ModelID { get; set; }
        public string Path { get; set; }

        public int x1 { get; set; }
        public int y1 { get; set; }
        public int x2 { get; set; }
        public int y2 { get; set; }
        
        //public class PhotoDBContext : DbContext
        //{
        //    public DbSet<Photo> Photos { get; set; }
        //}
    }
}