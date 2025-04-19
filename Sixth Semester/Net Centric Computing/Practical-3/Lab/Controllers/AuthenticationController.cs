using System.Security.Claims;
using Microsoft.AspNetCore.Authentication;
using Microsoft.AspNetCore.Authentication.Cookies;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
namespace Lab.Controllers
{
    public class AuthenticationController : Controller
    {
        [HttpGet]
        public IActionResult Login(string returnUrl = "/")
        {
            ViewData["returnUrl"] = returnUrl;
            return View();
        }
        [HttpPost]
        public async Task<IActionResult> Login(string uname, string pass, string returnUrl = "/")
        {
            if (uname == "aakashdhakal" && pass == "aakash")
            {
                var claims = new List<Claim> {
            new Claim(ClaimTypes.NameIdentifier, uname),
            new Claim(ClaimTypes.Name, uname),
            new Claim(ClaimTypes.Role, "Admin"),
            new Claim("CanEdit", "true") // Custom claim
        };
                var claimsIdentity = new ClaimsIdentity(claims, CookieAuthenticationDefaults.AuthenticationScheme);
                var claimsPrincipal = new ClaimsPrincipal(claimsIdentity);
                await HttpContext.SignInAsync(CookieAuthenticationDefaults.AuthenticationScheme, claimsPrincipal);

                TempData["UserName"] = uname; // Pass username to Dashboard
                return RedirectToAction("Dashboard", "Authentication");
            }
            ViewData["Error"] = "Invalid username or password";
            return View();
        }
        [Authorize(Roles = "Admin")]
        public IActionResult AdminPage()
        {
            return View("AdminPage");
        }
        [Authorize(Policy = "CanEditPolicy")]
        public IActionResult EditPage()
        {
            return View("EditPage");
        }
        [Authorize(Policy = "IsAakash")]
        public IActionResult SpecialPage()
        {
            return View("SpecialPage");
        }
        [HttpPost]
        public async Task<IActionResult> Logout()
        {
            await HttpContext.SignOutAsync(CookieAuthenticationDefaults.AuthenticationScheme);
            return RedirectToAction("Login");
        }
        [Authorize] // Ensure only authenticated users can access the Dashboard
        public IActionResult Dashboard()
        {
            return View();
        }

        
    }
}