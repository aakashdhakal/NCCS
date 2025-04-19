using Microsoft.AspNetCore.Mvc;
using Lab.Models;
using Microsoft.EntityFrameworkCore;
using System.Threading.Tasks;
namespace Lab.Controllers
{
    public class OfficerController : Controller
    {
        private readonly OfficerContext _context;
        public OfficerController(OfficerContext context)
        {
            _context = context;
        }
        public async Task<IActionResult> Index()
        {
            var officers = await _context.Officers.ToListAsync();
            return View(officers);
        }
        public IActionResult AddOfficer()
        {
            return View();
        }
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> RegisterOfficer(Officer officer)
        {
            if (ModelState.IsValid)
            {
                _context.Add(officer);
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Index));
            }
            return View(officer);
        }
        public async Task<IActionResult> EditOfficer(int id)
        {
            var officer = await _context.Officers.FindAsync(id);
            if (officer == null) return NotFound();
            return View(officer);
        }
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Update(int id, Officer officer)
        {
            if (id != officer.Id) return NotFound();
            if (ModelState.IsValid)
            {
                _context.Update(officer);
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Index));
            }
            return View(officer);
        }
        public async Task<IActionResult> Delete(int id)
        {
            var officer = await _context.Officers.FindAsync(id);
            if (officer == null) return NotFound();
            return View(officer);
        }
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> DeleteConfirmed(int id)
        {
            var officer = await _context.Officers.FindAsync(id);
            if (officer != null)
            {
                _context.Officers.Remove(officer);
                await _context.SaveChangesAsync();
            }
            return RedirectToAction(nameof(Index));
        }
    }
}