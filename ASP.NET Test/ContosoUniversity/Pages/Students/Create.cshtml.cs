using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using ContosoUniversity.Data;
using ContosoUniversity.Models;

namespace ContosoUniversity.Pages_Students
{
    public class CreateModel : PageModel
    {
        private readonly SchoolContext _context;

        public CreateModel(SchoolContext context)
        {
            _context = context;
        }

        public IActionResult OnGet()
        {
            return Page();
        }

        [BindProperty]
        public StudentVM StudentVM { get; set; }

        public async Task<IActionResult> OnPostAsync()
        {
            if (!ModelState.IsValid)
            {
                return Page();
            }

            var student = new Student
            {
                LastName = StudentVM.LastName,
                FirstMidName = StudentVM.FirstMidName,
                EnrollmentDate = StudentVM.EnrollmentDate
            };

            _context.Students.Add(student);
            await _context.SaveChangesAsync();
            return RedirectToPage("./Index");
        }
    }
}
