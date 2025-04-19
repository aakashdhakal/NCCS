using Microsoft.AspNetCore.Mvc;
using Lab.Models;


namespace Lab.Controllers
{
    public class EmployeeController : Controller
    {
        private readonly EmployeeContext _context;

        public EmployeeController(EmployeeContext context) // Constructor Injection
        {
            _context = context;
        }
        // GET: EmployeeController
        [HttpGet]
        public ActionResult Index()
        {
            return View();
        }

        public ActionResult Details()
        {
            // Create an instance of the Employee class
            Employee e = new()
            {
                Name = "Aakash Dhakal",
                Gender = "Male",
                Phone = "123-456-7890",
                Position = "Software Engineer",
                Department = "IT"
            };
            return View(e);
        }

        // [HttpGet]
        // public ActionResult AddEmployee()
        // {
        //     return View();
        // }

        // [HttpGet]
        // public ActionResult Edit(Guid id)
        // {
        //     var e = _context.Employees.FirstOrDefault(s => s.Id == id);
        //     if (e != null)
        //     {
        //         return View(e);
        //     }
        //     return RedirectToAction("DisplayEmployees");
        // }

        // [HttpGet]
        // public ActionResult DisplayEmployees()
        // {
        //     List<Employee> e = _context.Employees.ToList();
        //     return View(e);
        // }

        // [HttpPost]
        // public ActionResult Update(Employee e)
        // {
        //     _context.Employees.Update(e);
        //     _context.SaveChanges();
        //     return RedirectToAction("DisplayEmployees");
        // }

        // [HttpGet]
        // public ActionResult Delete(Guid id)
        // {
        //     var employee = _context.Employees.FirstOrDefault(s => s.Id == id);
        //     if (employee != null)
        //     {
        //         _context.Employees.Remove(employee);
        //         _context.SaveChanges();
        //     }
        //     return RedirectToAction("DisplayEmployees");
        // }

        // [HttpPost]
        // public ActionResult RegisterEmployee(Employee e)
        // {
        //     _context.Employees.Add(e);
        //     _context.SaveChanges();
        //     return RedirectToAction("DisplayEmployees");
        // }

    }
}
