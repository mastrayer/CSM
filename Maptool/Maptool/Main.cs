using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Maptool
{
    public partial class Main : Form
    {
        MainMenu mnuMain = new MainMenu();

        public Main()
        {
            InitializeComponent();


        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void menu_item_exit_MouseDown(object sender, EventArgs e)
        {
            label1.Text = "마우스 누름";
            MessageBox.Show("mouse down", "alarm");
        }
        private void menu_item_exit_MouseUp(object sender, EventArgs e)
        {
            label1.Text = "마우스 뗌";
            MessageBox.Show("mouse down", "alarm");
        }
    }
}
