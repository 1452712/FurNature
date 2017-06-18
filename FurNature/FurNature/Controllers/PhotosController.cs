using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Entity;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;
using FurNature.Models;

namespace FurNature.Controllers
{
    public class PhotosController : Controller
    {
        private ApplicationDbContext db = new ApplicationDbContext();

        // GET: Photos
        public ActionResult Index()
        {
            return View(db.Photos.ToList());
        }

        // GET: Photos/Details/5
        public ActionResult Details(string id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Photo photo = db.Photos.Find(id);
            if (photo == null)
            {
                return HttpNotFound();
            }
            return View(photo);
        }

        // GET: Photos/Create
        public ActionResult Create()
        {
            return View();
        }

        // POST: Photos/Create
        // 为了防止“过多发布”攻击，请启用要绑定到的特定属性，有关 
        // 详细信息，请参阅 http://go.microsoft.com/fwlink/?LinkId=317598。
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create([Bind(Include = "ID,UserID,ModelID,Path,x1,y1,x2,y2")] Photo photo)
        {
            if (ModelState.IsValid)
            {
                db.Photos.Add(photo);
                db.SaveChanges();
                return RedirectToAction("Index");
            }

            return View(photo);
        }
　
        // POST: Photos/CreatePhoto
        public ActionResult CreatePhoto(string email)
        {
            System.Random Random = new System.Random();
            int value = Random.Next(0, 999999);

            Photo photo = new Photo();
            photo.ID = value.ToString();
            photo.UserID = email;
            photo.Path = @"\Image\hsides\" + photo.UserID + "\\house.jpg";

            // 文件上传
            //if (file1.PostedFile.ContentLength > 0)
            //{
            //    if (File.Exists(@"C:\Users\WJM\Desktop\FilesUpLoad\" + file1.PostedFile.FileName))
            //    {
            //        Label1.Text = "文件已经存在";
            //    }
            //    else
            //    {
            //        file1.PostedFile.SaveAs(@"C:\Users\WJM\Desktop\FilesUpLoad\" + file1.PostedFile.FileName);
            //    }

            //}
            //else
            //{
            //    Label1.Text = "上传失败";
            //}


            if (ModelState.IsValid)
            {
                db.Photos.Add(photo);
                db.SaveChanges();
                return RedirectToAction("Edit", "Photos", new { id = "01" });
            }

            return RedirectToAction("Edit", "Photos", new { id = "01" });
        }

        // POST: Photos/EditPhoto
        public ActionResult EditPhoto(string id, string user_id, int x1, int y1, int x2, int y2)
        {
            Photo photo = new Photo();
            photo.ID = id;
            photo.ModelID = id;
            photo.x1 = x1;
            photo.x2 = x2;
            photo.y1 = y1;
            photo.y2 = y2;
                        
            //if (ModelState.IsValid)
            //{
                //db.Entry(photo).State = EntityState.Modified;
                //db.SaveChanges();
            //}
            //else
            //{
                //return RedirectToAction("Index", "Home", new { email = user_id });
            //}

            // 处理图片

            Model model = new Model();
            model.ID = id;
            model.UserID = user_id;
            model.Name = "Room" + id;
            model.ImgBack = "/Image/hsides/" + user_id + "/" + id + "/hback.jpg";
            model.ImgBottom = "/Image/hsides/" + user_id + "/" + id + "/hbottom.jpg";
            model.ImgTop = "/Image/hsides/" + user_id + "/" + id + "/htop.jpg";
            model.ImgLeft = "/Image/hsides/" + user_id + "/" + id + "/hleft.jpg";
            model.ImgRight = "/Image/hsides/" + user_id + "/" + id + "/hright.jpg";

            if (ModelState.IsValid)
            {
                //db.Models.Add(model);
                //db.SaveChanges();
                return RedirectToAction("Details", "Models", new { id = id });
            }
            return RedirectToAction("Details", "Models", new { id = id });
            //return RedirectToAction("Index", "Home", new { email = user_id });
        }

        // GET: Photos/Edit/5
        public ActionResult Edit(string id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Photo photo = db.Photos.Find(id);
            if (photo == null)
            {
                return HttpNotFound();
            }
            return View(photo);
        }

        // POST: Photos/Edit/5
        // 为了防止“过多发布”攻击，请启用要绑定到的特定属性，有关 
        // 详细信息，请参阅 http://go.microsoft.com/fwlink/?LinkId=317598。
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include = "ID,UserID,ModelID,Path,x1,y1,x2,y2")] Photo photo)
        {
            if (ModelState.IsValid)
            {
                db.Entry(photo).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            return View(photo);
        }

        // GET: Photos/Delete/5
        public ActionResult Delete(string id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Photo photo = db.Photos.Find(id);
            if (photo == null)
            {
                return HttpNotFound();
            }
            return View(photo);
        }

        // POST: Photos/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(string id)
        {
            Photo photo = db.Photos.Find(id);
            db.Photos.Remove(photo);
            db.SaveChanges();
            return RedirectToAction("Index");
        }

        protected override void Dispose(bool disposing)
        {
            if (disposing)
            {
                db.Dispose();
            }
            base.Dispose(disposing);
        }
    }
}
