using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace RazorPagesMovie.Models;

public class Movie
{
    public int Id { get; set; }

    [StringLength(60, MinimumLength = 3)]
    public string Title { get; set; } = string.Empty;

    [Display(Name = "Release Date"), DataType(DataType.Date)]
    public DateTime ReleaseDate { get; set; }

    [RegularExpression(@"^[A-Z]+[a-zA-Z\s]*$"), Required, StringLength(30)]
    public string Genre { get; set; } = string.Empty;

    [Range(1, 100), DataType(DataType.Currency)]
    [Column(TypeName = "decimal(18, 2)")]
    public decimal Price { get; set; }

    [RegularExpression(@"^[A-Z]+[a-zA-Z0-9""'\s-]*$"), StringLength(5)]
    public string Rating { get; set; } = string.Empty;
}

/* Agregar los paquetes NuGet y las herramientas EF:
 * dotnet tool uninstall --global dotnet-aspnet-codegenerator
 * dotnet tool install --global dotnet-aspnet-codegenerator
 * dotnet tool uninstall --global dotnet-ef
 * dotnet tool install --global dotnet-ef
 * dotnet add package Microsoft.EntityFrameworkCore.Design
 * dotnet add package Microsoft.EntityFrameworkCore.SQLite
 * dotnet add package Microsoft.VisualStudio.Web.CodeGeneration.Design
 * dotnet add package Microsoft.EntityFrameworkCore.SqlServer
 * dotnet add package Microsoft.EntityFrameworkCore.Tools
 *
 * Aplicar scaffolding al modelo de película
 * dotnet aspnet-codegenerator razorpage -m Movie -dc RazorPagesMovie.Data.RazorPagesMovieContext -udl -outDir Pages/Movies --referenceScriptLibraries --databaseProvider sqlite
 * Ayuda: 
 * dotnet aspnet-codegenerator razorpage -h
 */