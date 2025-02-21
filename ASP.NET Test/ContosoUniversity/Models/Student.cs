namespace ContosoUniversity.Models
{
    public class Student
    {
        public int ID { get; set; }
        public string LastName { get; set; } = string.Empty;
        public string FirstMidName { get; set; } = string.Empty;
        public DateTime EnrollmentDate { get; set; }
        public string? Secret { get; set; }

        public ICollection<Enrollment> Enrollments { get; set; }

        public Student()
        {
            LastName = string.Empty;
            FirstMidName = string.Empty;
        }   
    }
}