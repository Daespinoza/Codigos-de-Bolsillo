using System;
using System.ComponentModel.DataAnnotations;

namespace ContosoUniversity.Models
{
   public class StudentVM
   {
       public int ID { get; set; }

       [Display(Name = "Apellido")]
       public string LastName { get; set; }

       [Display(Name = "Nombre")]
       public string FirstMidName { get; set; }

       [Display(Name = "Fecha de inscripción")]
       [DataType(DataType.Date)]
       public DateTime EnrollmentDate { get; set; }

       // Propiedad calculada
       public string FullName
       {
           get { return $"{FirstMidName} {LastName}"; }
       }
   }

}
