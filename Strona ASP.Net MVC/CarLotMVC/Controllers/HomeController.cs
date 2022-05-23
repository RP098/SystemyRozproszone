using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace CarLotMVC.Controllers
{
    public class HomeController : Controller
    {
        public ActionResult Index()
        {
            return View();
        }

        public ActionResult About()
        {
            ViewBag.Message = "Firma Ag Super Car";

            return View();
        }
        public ActionResult Multimedia()
        {
            ViewBag.Message = "Skontaktuj się już dziś";

            return View();
        }

        public ActionResult Contact()
        {
            ViewBag.Message = "Skontaktuj się już dziś";

            return View();
        }
    }
}