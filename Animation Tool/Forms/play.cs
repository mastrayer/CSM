using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;
using System.Threading;

namespace Animation_Tool
{
    public partial class play : Form
    {
        public play()
        {
            InitializeComponent();        
        }
        public void Init()
        {
            playScene.Image = null;
        }
        private void play_FormClosing(object sender, FormClosingEventArgs e)
        {
            e.Cancel = true;
        }
        public void playAnimation(List<main.frameInfo> frames)
        {
            // Create new stopwatch
            Stopwatch stopwatch = new Stopwatch();

            // Write result
            foreach (main.frameInfo frame in frames)
            {
                playScene.Image = frame.sprite;
                // Begin timing
                stopwatch.Reset();
                stopwatch.Start();

                while (true)
                {
                    Application.DoEvents();

                    if (stopwatch.ElapsedMilliseconds >= frame.time)
                        break;
                }

                // Stop timing
                stopwatch.Stop();
            }
        }
    }
}
