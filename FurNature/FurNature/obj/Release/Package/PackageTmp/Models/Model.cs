using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Web;
using System.Data.Entity;
using System.Runtime.InteropServices;

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

        [DllImport("Add.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern int IntAdd(int x, int y);

        [DllImport("Add.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern double DoubleAdd(double x, double y);

        [DllImport("Add.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern bool BoolAdd(bool x, bool y);

        [DllImport("Add.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern IntPtr StringAdd(StringBuilder x, StringBuilder y);

        public string GetFileNameTop()
        {
            int test = IntAdd(1, 2);

            StringBuilder folder = new StringBuilder("/Image/hsides/" + UserID + "_" + ID);
            StringBuilder image = new StringBuilder("/" + this.ImgTop);
            //string model = StringAdd("/", ID);
            //string image = StringAdd("/", ImgTop);

            IntPtr path = StringAdd(folder, image);
            string res = Marshal.PtrToStringAnsi(path);
            //path = StringAdd(path, model);
            //return StringAdd(path, image);
            return res;
        }

        public string GetFileNameBottom()
        {
            int test = IntAdd(1, 2);

            StringBuilder folder = new StringBuilder("/Image/hsides/" + UserID + "_" + ID);
            StringBuilder image = new StringBuilder("/" + this.ImgBottom);

            IntPtr path = StringAdd(folder, image);
            string res = Marshal.PtrToStringAnsi(path);
            return res;
        }

        public string GetFileNameLeft()
        {
            int test = IntAdd(1, 2);

            StringBuilder folder = new StringBuilder("/Image/hsides/" + UserID + "_" + ID);
            StringBuilder image = new StringBuilder("/" + this.ImgLeft);

            IntPtr path = StringAdd(folder, image);
            string res = Marshal.PtrToStringAnsi(path);
            return res;
        }

        public string GetFileNameRight()
        {
            int test = IntAdd(1, 2);

            StringBuilder folder = new StringBuilder("/Image/hsides/" + UserID + "_" + ID);
            StringBuilder image = new StringBuilder("/" + this.ImgRight);

            IntPtr path = StringAdd(folder, image);
            string res = Marshal.PtrToStringAnsi(path);
            return res;
        }

        public string GetFileNameBack()
        {
            int test = IntAdd(1, 2);

            StringBuilder folder = new StringBuilder("/Image/hsides/" + UserID + "_" + ID);
            StringBuilder image = new StringBuilder("/" + this.ImgBack);

            IntPtr path = StringAdd(folder, image);
            string res = Marshal.PtrToStringAnsi(path);
            return res;
        }
    }
}