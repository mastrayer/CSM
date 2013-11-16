using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Animation_Tool
{
    public partial class main : Form
    {
        public main()
        {            
            InitializeComponent();

            LoadedSprite.Size = new Size(1000, 3000);
            LoadedSprite.Image = new Bitmap(1000, 2000);
        }
    }
}
