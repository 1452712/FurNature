using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace FurNature.Models
{
    public class User
    {
        public string ID { get; set; }
        public string Name { get; set; }
        public string Pwd { get; set; }
        public IEnumerable<string> SelectFurniture { get; set; }
    }
}