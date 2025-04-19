
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.SqlServer;

namespace Lab.Models
{
    public class OfficerContext : DbContext
    {
        public OfficerContext(DbContextOptions<OfficerContext> options) : base(options)
        {
        }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            optionsBuilder.UseSqlServer("Data Source=AAKASH-DHAKAL;Initial Catalog=dotnet;Integrated Security=True;TrustServerCertificate=True");
        }

        public DbSet<Officer> Officers { get; set; }

    }
}