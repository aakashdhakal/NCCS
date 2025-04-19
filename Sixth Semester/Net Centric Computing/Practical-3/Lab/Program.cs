using Microsoft.EntityFrameworkCore;
using Lab.Models;
using Microsoft.AspNetCore.Authentication.Cookies;
using System.Security.Claims;

var builder = WebApplication.CreateBuilder(args);

// Add services to the container.
builder.Services.AddControllersWithViews();

// Add session services
builder.Services.AddDistributedMemoryCache();
builder.Services.AddSession(options =>
{
    options.IdleTimeout = TimeSpan.FromMinutes(30); // Set session timeout
    options.Cookie.HttpOnly = true;
    options.Cookie.IsEssential = true;
});

builder.Services.AddAuthentication(CookieAuthenticationDefaults.AuthenticationScheme)
    .AddCookie(options =>
    {
        options.LoginPath = "/Authentication/Login"; // Redirect to login page
        options.AccessDeniedPath = "/Authentication/AccessDenied"; // Redirect on access denied
    });

builder.Services.AddAuthorization(options =>
{
    options.AddPolicy("CanEditPolicy", policy => policy.RequireClaim("CanEdit", "true"));
    options.AddPolicy("IsAakash", policy => policy.RequireClaim(ClaimTypes.Name, "aakashdhakal"));
});

// Register DbContext
builder.Services.AddDbContext<EmployeeContext>(options =>
    options.UseSqlServer(builder.Configuration.GetConnectionString("cs")));
// Register OfficerContext
builder.Services.AddDbContext<OfficerContext>(options =>
options.UseSqlServer(builder.Configuration.GetConnectionString("cs")));

var app = builder.Build();

// Configure the HTTP request pipeline.
if (!app.Environment.IsDevelopment())
{
    app.UseExceptionHandler("/Home/Error");
    app.UseHsts(); // Enforce HTTPS
}

app.UseHttpsRedirection();
app.UseStaticFiles(); // Enable serving static files

app.UseRouting();
app.UseSession(); // Enable session middleware
app.UseAuthorization();

app.MapControllerRoute(
    name: "default",
    pattern: "{controller=Home}/{action=Index}/{id?}"
);

app.Run();
