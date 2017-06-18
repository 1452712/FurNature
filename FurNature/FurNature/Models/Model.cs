using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data.Entity;

namespace FurNature.Models
{
    public class Model
    {
        public string ID { get; set; }
        public string Name { get; set; }
        public string UserID { get; set; }
        public string ImgTop { get; set; }
        public string ImgBottom { get; set; }
        public string ImgLeft { get; set; }
        public string ImgRight { get; set; }
        public string ImgBack { get; set; }

        //public class ModelDBContext : DbContext
        //{
        //    public DbSet<Model> Models { get; set; }
        //}
    }
}