using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
namespace Lab.Controllers
{
    public class StateController : Controller
    {
        public IActionResult SetSession()
        {
            HttpContext.Session.SetString("User", "Aakash");
            TempData["Message"] = "Session value has been set!";
            return RedirectToAction("GetSession");
        }

        public IActionResult GetSession()
        {
            string user = HttpContext.Session.GetString("User") ?? string.Empty;
            ViewBag.User = user ?? "No session found!";
            ViewBag.Message = TempData["Message"];
            return View("SessionView");
        }

        public IActionResult TempDataDemo()
        {

            ViewData["data1"] = "The data from view data (Aakash)";
            ViewBag.data2 = "The data from view bag (CSIT)";
            TempData["data3"] = "The data from temp data (Gothatar)";
            return View();
        }
        public IActionResult SetCookie()
        {
            CookieOptions option = new CookieOptions();
            option.Expires = DateTime.Now.AddMinutes(10); // Cookie expires in 10 minutes
            Response.Cookies.Append("UserName", "Aakash Dhakal", option);
            ViewBag.Message = "Cookie has been set!";
            return View("ClientStateView");
        }

        [HttpGet]
        public IActionResult GetCookie()
        {
            string userName = Request.Cookies["UserName"] ?? string.Empty;
            ViewBag.Message = userName ?? "No cookie found!";
            return View("ClientStateView");
        }
        public IActionResult QueryStringExample(string name, int age)
        {
            ViewBag.Message = $"Name: {name}, Age: {age}";
            return View("ClientStateView");
        }
        [HttpPost]
        public IActionResult SubmitHidden(string HiddenData)
        {
            ViewBag.Message = "Hidden Field Value: " + HiddenData;
            return View("ClientStateView");
        }
    }
}