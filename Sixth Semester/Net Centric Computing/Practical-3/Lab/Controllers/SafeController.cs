using System;
using System.Web;
using Microsoft.AspNetCore.Mvc;
namespace SecureApp.Controllers
{
    public class SafeController : Controller
    {
        // GET: Secure Form (Prevents CSRF)
        [HttpGet]
        public IActionResult SecureForm()
        {
            return View();
        }
        // POST: Secure Form Handling (Prevents CSRF & XSS)
        [HttpPost]
        [ValidateAntiForgeryToken] // CSRF Protection
        public IActionResult SecureForm(string userInput)
        {
            if (string.IsNullOrWhiteSpace(userInput))
            {
                ViewBag.Message = "Input cannot be empty.";
                return View();
            }
            // Prevent XSS (Cross-Site Scripting) by encoding input
            string safeInput = HttpUtility.HtmlEncode(userInput);
            ViewBag.Message = "Processed Input: " + safeInput;
            return View();
        }
        // GET: Prevent Open Redirect Attack
        public IActionResult SafeRedirect(string returnUrl)
        {
            Uri redirectUri;
            if (Uri.TryCreate(returnUrl, UriKind.RelativeOrAbsolute, out redirectUri))
            {
                if (!redirectUri.IsAbsoluteUri || redirectUri.Host == Request.Host.Host) // Only allow internal redirects
                {
                    return Redirect(returnUrl);
                }
            }
            return RedirectToAction("SecureForm"); // Safe default redirection
        }
    }
}
