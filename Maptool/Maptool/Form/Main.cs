﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Compression;
using System.IO;

using Ionic.Zip;

using System.Xml;
using System.Collections.Specialized;


namespace Maptool
{
    public partial class Main : Form
    {
        // form
        public main_map mainMap;
        public TileSelectForm TileSelectWindow = null;

        // values
        Bitmap minimapImage;
        public double Zoom;
        public int TileSize = Convert.ToInt32(Maptool.Properties.Resources.TILESIZE);
        public main_map.Tile SelectedTileInfo;
        public List<BitmapList> TileList = new List<BitmapList>();
        public int bitmapID = 0;
        public Point selectedPoint = new Point(0,0);

        public class BitmapList
        {
            public int ID;
            public Bitmap image;

            public BitmapList(int id, Bitmap img)
            {
                this.ID = id;
                this.image = img;
            }
        }

        public Bitmap drawGrid(Bitmap image, Pen gridPen, bool isDot, int size)
        {
            Graphics g = Graphics.FromImage(image);
            if (isDot == true)
                gridPen.DashStyle = System.Drawing.Drawing2D.DashStyle.DashDot;

            for (int i = 0; i < image.Width / size; ++i)
            {
                for (int j = 0; j < image.Height / size; ++j)
                    g.DrawRectangle(gridPen, i * size, j * size, size, size);
            }

            g.Dispose();
            return image;
        }
        private void SortBitmapID()
        {
            for (int i = 0; i < TileList.Count; ++i)
            {
                if (i != TileList[i].ID)
                {
                    for (int j = 0; j < mainMap.MapSize.Width; ++j)
                    {
                        for (int k = 0; k < mainMap.MapSize.Height; ++k)
                        {
                            if (mainMap.grid[j, k].TIleSetID == TileList[i].ID)
                                mainMap.grid[j, k].TIleSetID = i;
                        }
                    }
                    TileList[i].ID = i;
                }
            }
            bitmapID = TileList.Count;
        }
        public void Minimap_update()
        {
            if (minimapImage != null)
                minimapImage.Dispose();

            Image img = mainMap.flag;
            minimapImage = new Bitmap(img.Width, img.Height);
            Graphics g = Graphics.FromImage(minimapImage);
            Pen pen = new Pen(Color.Black, 10);

            g.DrawImage(img, 0, 0, minimapImage.Width, minimapImage.Height);
            g.DrawRectangle(pen, new Rectangle(mainMap.HorizontalScroll.Value, mainMap.VerticalScroll.Value, main_map_panel.Width - 30, main_map_panel.Height - 50));

            minimap.Image = minimapImage;
            g.Dispose();
            pen.Dispose();
        }
        public void init()
        {
            layers.SelectedIndex = 0;
            magnification.Text = "100%";
            Zoom = Convert.ToDouble(magnification.Text.Remove(magnification.Text.Length - 1)) / 100;

            TileSelectWindow = new TileSelectForm(this);

            mainMap_init(16, 16);
            Minimap_update();

            TileSelectWindow.Show();
        }
        public void mainMap_init(int width, int height)
        {
            if (mainMap != null)
                mainMap.Dispose();

            mainMap = new main_map(width, height, this);

            mainMap.TopLevel = false;
            mainMap.TopMost = true;
            this.main_map_panel.Controls.Add(mainMap);

            mainMap.Parent = this.main_map_panel;
            mainMap.Text = "";

            mainMap.ControlBox = false;

            this.Main_Resize(null, null);
            mainMap.SetBounds(0, 0, mainMap.Parent.Size.Width - 30, mainMap.Parent.Size.Height - 50);

            mainMap.Show();
        }
        public Main()
        {
            this.MouseWheel += new MouseEventHandler(test);
            InitializeComponent();
            init();
        }
        void test(object sender, MouseEventArgs e)
        {
            MessageBox.Show("휠");
        }
        private void menu_item_new_Click(object sender, EventArgs e)
        {
            new_map newForm = new new_map(this);
            newForm.Owner = this;
            newForm.Show();
        }
        private void XMLCreate(string FileName)
        {
            SortBitmapID();
            XmlTextWriter textWriter = new XmlTextWriter(@"map.xml", Encoding.UTF8);

            textWriter.Formatting = Formatting.Indented;
            textWriter.WriteStartDocument();

            textWriter.WriteStartElement("map");
            {
                // 기본적인 맵 정보
                textWriter.WriteStartElement("mapInfo");
                {
                    // map size
                    textWriter.WriteStartElement("size");
                    {
                        textWriter.WriteStartAttribute("width");
                        textWriter.WriteString(mainMap.MapSize.Width.ToString());
                        textWriter.WriteEndAttribute();

                        textWriter.WriteStartAttribute("height");
                        textWriter.WriteString(mainMap.MapSize.Height.ToString());
                        textWriter.WriteEndAttribute();
                    }
                    textWriter.WriteEndElement();

                    // used tile set
                    textWriter.WriteStartElement("usedTileSet");
                    {
                        textWriter.WriteStartAttribute("count");
                        textWriter.WriteString(TileList.Count.ToString());
                        textWriter.WriteEndAttribute();

                        for (int i = 0; i < TileList.Count; ++i)
                            TileList[i].image.Save("TileSet" + i.ToString());
                    }
                    textWriter.WriteEndElement();
                }
                textWriter.WriteEndElement();

                // 배치된 타일의 이미지 / 속성
                textWriter.WriteStartElement("tileInfo");
                {
                    for (int i = 0; i < mainMap.MapSize.Width; ++i)
                    {
                        for (int j = 0; j < mainMap.MapSize.Height; ++j)
                        {
                            textWriter.WriteStartElement("t" + i.ToString() + "-" + j.ToString());
                            {
                                textWriter.WriteStartAttribute("isFull");
                                textWriter.WriteString(mainMap.grid[i, j].isFull == true ? "true" : "false");
                                textWriter.WriteEndAttribute();

                                textWriter.WriteStartElement("TileImageInfo");
                                {
                                    textWriter.WriteStartAttribute("Index");
                                    textWriter.WriteString(mainMap.grid[i, j].TIleSetID.ToString());
                                    textWriter.WriteEndAttribute();

                                    textWriter.WriteStartAttribute("X");
                                    textWriter.WriteString(mainMap.grid[i, j].TileLocation.X.ToString());
                                    textWriter.WriteEndAttribute();

                                    textWriter.WriteStartAttribute("Y");
                                    textWriter.WriteString(mainMap.grid[i, j].TileLocation.Y.ToString());
                                    textWriter.WriteEndAttribute();
                                }
                                textWriter.WriteEndElement();

                                textWriter.WriteStartElement("Attribute");
                                {
                                    textWriter.WriteStartAttribute("move");
                                    textWriter.WriteString(mainMap.grid[i, j].attributeMove == true ? "true" : "false");
                                    textWriter.WriteEndAttribute();

                                    textWriter.WriteStartAttribute("height");
                                    textWriter.WriteString(mainMap.grid[i, j].attributeHeight.ToString());
                                    textWriter.WriteEndAttribute();
                                }
                                textWriter.WriteEndElement();
                            }
                            textWriter.WriteEndElement();
                        }
                    }
                }
                textWriter.WriteEndElement();
            }
            textWriter.WriteEndElement();

            textWriter.WriteEndDocument();
            textWriter.Close();
        }
        private void CSMCreate(string FileName)
        {
            DirectoryInfo DI = new DirectoryInfo(System.IO.Directory.GetCurrentDirectory());
            FileInfo[] fi = new FileInfo[TileList.Count + 1];
            String[] files = new String[fi.Length];

            files[0] = "map.xml";
            for (int i = 0; i < fi.Length - 1; i++)
                files[i + 1] = "TileSet" + i.ToString();

            byte[] b = null;
            string d = null;

            using (ZipFile zip = new ZipFile())
            {
                foreach (string file in files)
                    zip.AddFile(file);
                zip.Save(FileName);
            }
            foreach (string file in files)
                File.Delete(file);
        }
        private void OpenCSMFile(string FileName)//(String fileName)
        {
            int usedTileSetCount = 0;
            string zipToUnpack = FileName;
            MemoryStream ms;

            TileList.Clear();
            using (ZipFile zip1 = ZipFile.Read(zipToUnpack))
            {
                foreach (ZipEntry a in zip1)
                {
                    ms = new MemoryStream();
                    a.Extract(ms);
                    ms.Seek(0, SeekOrigin.Begin);

                    // XML
                    if (a.FileName.ToLower().IndexOf(".xml") > 0)
                    {
                        XmlDocument xmldoc = new XmlDocument();
                        xmldoc.Load(ms);

                        XmlNodeList xnList = xmldoc.SelectNodes("map/mapInfo"); //접근할 노드
                        foreach (XmlNode xn in xnList)
                        {
                            mainMap.MapSize.Width = Convert.ToInt32(xn["size"].Attributes["width"].Value);
                            mainMap.MapSize.Height = Convert.ToInt32(xn["size"].Attributes["height"].Value);
                            usedTileSetCount = Convert.ToInt32(xn["usedTileSet"].Attributes["count"].Value);
                        }
                        mainMap_init(mainMap.MapSize.Width, mainMap.MapSize.Height);

                        for (int i = 0; i < mainMap.MapSize.Width; ++i)
                        {
                            for (int j = 0; j < mainMap.MapSize.Height; ++j)
                            {
                                xnList = xmldoc.SelectNodes("map/tileInfo/t" + i.ToString() + "-" + j.ToString());
                                mainMap.grid[i,j].isFull = xmldoc.SelectSingleNode("map/tileInfo/t" + i.ToString() + "-" + j.ToString()).Attributes["isFull"].InnerText == "true" ? true : false;

                                if (!mainMap.grid[i, j].isFull)
                                    continue;

                                foreach (XmlNode xn in xnList)
                                {
                                    //mainMap.grid[i, j].Attribute = Convert.ToInt32(attribute);
                                    mainMap.grid[i, j].TIleSetID = Convert.ToInt32(xn["TileImageInfo"].Attributes["Index"].InnerText);
                                    mainMap.grid[i, j].TileLocation.X = Convert.ToInt32(xn["TileImageInfo"].Attributes["X"].InnerText);
                                    mainMap.grid[i, j].TileLocation.Y = Convert.ToInt32(xn["TileImageInfo"].Attributes["Y"].InnerText);
                                    mainMap.grid[i, j].attributeMove = xn["Attribute"].Attributes["move"].InnerText == "true" ? true : false;
                                    mainMap.grid[i, j].attributeHeight = Convert.ToInt32(xn["Attribute"].Attributes["height"].InnerText);
 
                                }
                            }
                        }
                    }
                    else
                        TileList.Add(new BitmapList(bitmapID++, new Bitmap(ms)));

                    ms.Dispose();
                }
                
            }
            for (int i = 0; i < mainMap.MapSize.Width; ++i)
            {
                for (int j = 0; j < mainMap.MapSize.Height; ++j)
                {
                    if(mainMap.grid[i,j].isFull)
                        mainMap.grid[i, j].tile = TileList[mainMap.grid[i, j].TIleSetID].image.Clone(new Rectangle(new Point(mainMap.grid[i, j].TileLocation.X, mainMap.grid[i, j].TileLocation.Y), new Size(TileSize, TileSize)), TileList[mainMap.grid[i, j].TIleSetID].image.PixelFormat);
                }
            }

            TileSelectWindow.changeImage(TileList.Count - 1);
            mainMap.refresh();
            Minimap_update();
        }
        private void menu_item_save_Click(object sender, EventArgs e)
        {
            SaveFileDialog saveFileDialog1 = new SaveFileDialog();

            saveFileDialog1.Filter = "CSM map files (*.csm)|*.csm";
            saveFileDialog1.FilterIndex = 1;
            saveFileDialog1.RestoreDirectory = true;
            saveFileDialog1.InitialDirectory = System.IO.Directory.GetCurrentDirectory();

            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                String fileName = saveFileDialog1.FileName;
                XMLCreate(fileName);
                CSMCreate(fileName);
            }
        }
        private void menu_item_open_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog1 = new OpenFileDialog();

            openFileDialog1.Filter = "CSM Map files|*.CSM";
            openFileDialog1.FilterIndex = 1;
            openFileDialog1.RestoreDirectory = true;
            openFileDialog1.InitialDirectory = System.IO.Directory.GetCurrentDirectory();

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                OpenCSMFile(openFileDialog1.FileName);
                //                 string zipToUnpack = "c:\\test\\1000.zip";
                //                 string unpackDirectory = "c:\\test\\temp\\";
                // 
                //                 string f = string.Empty;
                //                 Bitmap bm = null;
                //                 MemoryStream ms;
                // 
                //                 using (ZipFile zip = ZipFile.Read(zipToUnpack))
                //                 {
                //                     foreach (ZipEntry E in zip)
                //                     {
                //                         if (E.FileName.ToLower().IndexOf(".jpg") > 0)
                //                         {
                //                             ms = new MemoryStream();
                //                             E.Extract(ms);
                //                             try
                //                             {
                //                                 bm = new Bitmap(ms);
                //                                 //f = unpackDirectory + E.FileName.ToLower().Replace(".bmp", ".jpg");
                //                                 //bm.Save(f, System.Drawing.Imaging.ImageFormat.Jpeg);
                //                             }
                //                             catch (Exception ex)
                //                             {
                //                                 Console.WriteLine("File: " + E.FileName + " " + ex.ToString());
                //                             }
                //                             ms.Dispose();
                //                         }
                //                     }
                //                 }

                //string sDirPath = Application.StartupPath + "\\temp";
                //DirectoryInfo di = new DirectoryInfo(sDirPath);
                //if (di.Exists == false)
                //   di.Create();

                //                 string zipToUnpack = openFileDialog1.FileName;
                //                 MemoryStream ms;
                //                 //string unpackDirectory = "temp\\";
                // 
                //                 using (ZipFile zip1 = ZipFile.Read(zipToUnpack))
                //                 {
                //                     foreach (ZipEntry a in zip1)
                //                     {
                //                         ms = new MemoryStream();
                //                         a.Extract(ms);
                // 
                //                         // XML
                //                         if (a.FileName.ToLower().IndexOf(".xml") > 0)
                //                         {
                //                             XmlDocument b = new XmlDocument();
                //                             b.Load(ms);
                // 
                //                             XMLRead(b);
                //                         }
                //                         else
                //                         {
                //                             //a.Extract(unpackDirectory, ExtractExistingFileAction.OverwriteSilently);
                //                         }
                //                     }
                //                 }
                //XMLRead(@"temp\\map.xml");
                //Directory.Delete("temp\\", true);
            }
        }
        private void menu_item_exit_Click(object sender, EventArgs e)
        {
            Environment.Exit(0);
        }
        private void Main_Resize(object sender, EventArgs e)
        {
            // main_map resizing
            main_map_panel.Size = new Size(this.Size.Width - this.main_map_panel.Location.X, this.Size.Height - this.main_map_panel.Location.Y - 15);
            mainMap.SetBounds(0, 0, mainMap.Parent.Size.Width - 10, mainMap.Parent.Size.Height - 30);

            // contents resizing
            contents.Size = new Size(contents.Size.Width, this.Size.Height - minimap.Size.Height - Attribute_panel.Size.Height - status_panel.Size.Height);
            // 
            Minimap_update();
        }
        private void magnification_TextChanged(object sender, EventArgs e)
        {
            Zoom = Convert.ToDouble(magnification.Text.Remove(magnification.Text.Length - 1)) / 100;
        }
        private void minimapViewMove(MouseEventArgs e)
        {
            double w = e.X * TileSize / (minimap.Width / mainMap.MapSize.Width);
            double h = e.Y * TileSize / (minimap.Height / mainMap.MapSize.Height);

            if (mainMap.VerticalScroll.Visible)
                mainMap.VerticalScroll.Value = Convert.ToInt32(h);
            if (mainMap.HorizontalScroll.Visible)
                mainMap.HorizontalScroll.Value = Convert.ToInt32(w);

            mainMap.PerformLayout();
            Minimap_update();
        }

        bool isMinimapDrag = false;
        private void minimap_MouseDown(object sender, MouseEventArgs e)
        {
            isMinimapDrag = true;
            minimapViewMove(e);
        }
        private void minimap_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.X <= 0 || e.X >= minimap.Width || e.Y <= 0 || e.Y >= minimap.Height) return;
            if (isMinimapDrag)
                minimapViewMove(e);
        }
        private void minimap_MouseUp(object sender, MouseEventArgs e)
        {
            isMinimapDrag = false;
        }
        public void updateAttributePanel(int x, int y)
        {
             selectedPoint.X = x;
             selectedPoint.Y = y;
 
             attribute_move.Checked = mainMap.grid[x, y].attributeMove;
             attribute_height.Text = mainMap.grid[x, y].attributeHeight.ToString();
             attribute_index.Text = x.ToString() + "/" + y.ToString();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            String test = mainMap.grid[0, 0].attributeMove.ToString() + "." + mainMap.grid[0, 0].attributeHeight.ToString() + " : " + "0/0\n";

            test += mainMap.grid[0, 1].attributeMove.ToString() + "." + mainMap.grid[0, 1].attributeHeight.ToString() + " : " + "0/1\n";
            test += mainMap.grid[1, 0].attributeMove.ToString() + "." + mainMap.grid[1, 0].attributeHeight.ToString() + " : " + "1/0\n";
            test += mainMap.grid[1, 1].attributeMove.ToString() + "." + mainMap.grid[1, 1].attributeHeight.ToString() + " : " + "1/1\n";
            MessageBox.Show(test);
        }

        private void attribute_OK_Click(object sender, EventArgs e)
        {
            mainMap.grid[selectedPoint.X, selectedPoint.Y].attributeMove = attribute_move.Checked;
            mainMap.grid[selectedPoint.X, selectedPoint.Y].attributeHeight = Convert.ToInt32(attribute_height.Text);
        }

        private void isNumber(object sender, KeyPressEventArgs e)
        {
            if (!(Char.IsDigit(e.KeyChar)) && e.KeyChar != Convert.ToChar(Keys.Back))
            {
                //숫자입력만 받도록 한다.
                e.Handled = true;
            }
        }
    }
}
