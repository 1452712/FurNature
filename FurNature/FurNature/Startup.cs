using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(FurNature.Startup))]
namespace FurNature
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
