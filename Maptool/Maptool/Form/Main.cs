using System;
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
using System.Runtime.InteropServices;

using System.Xml;
using System.Collections.Specialized;


namespace Maptool
{
    public partial class Main : Form
    {
        //[DllImport("Ionic.Zip.dll")]
        //public static extern int TestFunc(int a, int b);
        //public static extern 

        public void test()
        {
            DirectoryInfo DI = new DirectoryInfo(@"C:\test");
            FileInfo[] fi = DI.GetFiles();
            String[] files = new String[fi.Length];
            for (int i = 0; i < fi.Length; i++)
                files[i] = fi[i].FullName;

            byte[] b = null;
            string d = null;

            using (ZipFile zip = new ZipFile())
            {

                foreach (string file in files)
                {
                    b = System.Text.Encoding.Default.GetBytes(file);
                    d = System.Text.Encoding.GetEncoding("IBM437").GetString(b);
                    zip.AddEntry(d, "", File.ReadAllBytes(file));
                }
                zip.Save(@"c:\test\test.zip");
            }
        }



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
                    for(int j=0; j<mainMap.MapSize.Width; ++j)
                    {
                        for (int k = 0; k < mainMap.MapSize.Height; ++k)
                        {
                            if (mainMap.grid[j,k].TIleSetID == TileList[i].ID)
                                mainMap.grid[j, k].TIleSetID = i;
                        }
                    }
                    TileList[i].ID = i;
                }
            }
            bitmapID = TileList.Count;
        }
        private void XMLCreate()
        {
            // 생성할 XML 파일 경로와 이름, 인코딩 방식을 설정합니다.
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

                        for (int i = 0; i < TileList.Count; ++i )
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
                            textWriter.WriteStartElement(i.ToString() + "/" + j.ToString());
                            {
                                textWriter.WriteStartElement("TileSetIndex");
                                textWriter.WriteString(mainMap.grid[i, j].TIleSetID.ToString());
                                textWriter.WriteEndElement();

                                textWriter.WriteStartElement("Location");
                                textWriter.WriteString(mainMap.grid[i, j].TileLocation.X.ToString() + "/" + mainMap.grid[i, j].TileLocation.Y.ToString());
                                textWriter.WriteEndElement();

                                textWriter.WriteStartElement("Attribute");
                                textWriter.WriteString(mainMap.grid[i, j].Attribute.ToString());
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



            /////////////////////////////////////////////////////////////////////////////////////////////////////////

            

            /*

            FileStream sourceFile = File.OpenRead(@"C:\test\a.txt");
            FileStream destFile = File.Create(@"C:\test\result.zip");
            GZipStream compStream = new GZipStream(destFile, CompressionMode.Compress);

            try
            {
                int theByte = sourceFile.ReadByte();
                while (theByte != -1)
                {
                    compStream.WriteByte((byte)theByte);
                    theByte = sourceFile.ReadByte();
                }
            }
            finally
            {
                compStream.Flush();
                compStream.Dispose();
            }


            string sourcepath2 = @"C:\test\result.zip";
            string destFolder2 = @"C:\test\result\";
            string destFilename2 = string.Format("sample_{0}.zip", DateTime.Now.ToString("MM_dd_yyyy"));
            string destpath2 = System.IO.Path.Combine(destFolder2, destFilename2);
            FileStream sourceFile2 = File.OpenRead(sourcepath2);
            FileStream destFile2 = File.Create(destpath2);
            GZipStream compStream2 = new GZipStream(destFile2, CompressionMode.Compress);

            try
            {
                int theByte2 = sourceFile2.ReadByte();
                while (theByte2 != -1)
                {
                    compStream2.WriteByte((byte)theByte2);
                    theByte2 = sourceFile2.ReadByte();
                }
            }
            finally
            {
                compStream2.Flush();
                compStream2.Dispose();
            }
             */
        }
        public static void Compress(FileInfo fileToCompress)
        {
            using (FileStream originalFileStream = fileToCompress.OpenRead())
            {
                if ((File.GetAttributes(fileToCompress.FullName) & FileAttributes.Hidden) != FileAttributes.Hidden & fileToCompress.Extension != ".gz")
                {
                    using (FileStream compressedFileStream = File.Create(fileToCompress.FullName + ".gz"))
                    {
                        using (GZipStream compressionStream = new GZipStream(compressedFileStream, CompressionMode.Compress))
                        {
                            originalFileStream.CopyTo(compressionStream);
                        }
                    }
                }
            }
        }

        public static void Decompress(FileInfo fileToDecompress)
        {
            using (FileStream originalFileStream = fileToDecompress.OpenRead())
            {
                string currentFileName = fileToDecompress.FullName;
                string newFileName = currentFileName.Remove(currentFileName.Length - fileToDecompress.Extension.Length);

                using (FileStream decompressedFileStream = File.Create(newFileName))
                {
                    using (GZipStream decompressionStream = new GZipStream(originalFileStream, CompressionMode.Decompress))
                    {
                        decompressionStream.CopyTo(decompressedFileStream);
                    }
                }
            }
        }

        private void ReadXML()
        {
//             string folder = @"c:\Some\Folder";
//             string output = @"D:\OtherFolder";
// 
//             string outputFilename = Path.Combine(output, string.Format("Archive{0}.zip", DateTime.Now.ToString("yyyymmDD")));
// 
//             System.IO.Compression.GZipStream.ZipFIle a;
//             using (ZipFile zip = new ZipFile())
//             {
//                 // Add all files in directory
//                 foreach(var file in Directory.EnumerateFiles(folder))
//                    zip.AddFile(file);
// 
//                 // Save to output filename
//                 zip.Save(outputFilename);
//             }

            XmlDocument xmldoc = new XmlDocument();
            xmldoc.Load(@"test.xml");
            XmlElement root = xmldoc.DocumentElement;

            // 노드 요소들
            XmlNodeList nodes = root.ChildNodes;

            // 노드 요소의 값을 읽어 옵니다.
            foreach (XmlNode node in nodes)
            {
                switch (node.Name)
                {
                    case "root_a":
                        MessageBox.Show(node.InnerText);
                        break;

                    case "root_b":

                        MessageBox.Show(node["b"].InnerText + "." + node["bb"].InnerText);
                        string b = node["b"].InnerText;
                        string bb = node["bb"].InnerText;
                        break;

                    case "root_c":

                        MessageBox.Show((int.Parse(node.InnerText)).ToString());
                        int c = int.Parse(node.InnerText);
                        break;
                }
            }
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

            test();

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

        private void menu_item_save_Click(object sender, EventArgs e)
        {
            XMLCreate();
            SaveFileDialog saveFileDialog1 = new SaveFileDialog();

            saveFileDialog1.Filter = "XML files (*.xml)|*.xml|CSM map files (*.csm)|*.csm";
            saveFileDialog1.FilterIndex = 1;
            saveFileDialog1.RestoreDirectory = true;
            saveFileDialog1.InitialDirectory = System.IO.Directory.GetCurrentDirectory();

            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
//                if (saveFileDialog1.OpenFile() != null)
                {
                    String a = saveFileDialog1.FileName;
                    saveFileDialog1.Dispose();
                    // Code to write the stream goes here.

                    XmlDocument xml = new XmlDocument();
                    xml.AppendChild(xml.CreateXmlDeclaration("1.0", "utf-8", "yes"));

                    XmlNode test = xml.CreateElement("Map");
                    test.Value = mainMap.MapSize.Width.ToString() + ":" + mainMap.MapSize.Height.ToString();
                    xml.AppendChild(test);
                    //XmlNode root = xml.CreateElement("", "Root", "");
                    //xml.AppendChild(root);
                    //XmlNode test = xml.CreateElement("");

                    xml.Save(a);
                    
                    

//                     XmlTextReader reader = new XmlTextReader(saveFileDialog1.FileName); // xml 파일을 엽니다
// 
//                     while (reader.Read()) //xml 을 읽습니다.
//                     {
//                         switch (reader.LocalName) // 속성을 읽습니다.
//                         {
//                             case "thumbnail": // thumbnail 이라는 속성이 있을때 다음 명령을 실행합니다.
//                                 string str = reader.ReadElementContentAsString(); //str 에 속성값을 지정합니다.
//                                 listBox1.Items.Add(str); //리스트 박스 1 에 str 을 넣습니다.
//                                 break;
//                             case "total": // total 이라는 속성이 있을경우 다음명령을 실행합니다.
//                                 label3.Text = reader.ReadElementContentAsString() + "개";
//                                 break;
//                         }
//                     }

                    
                }
            }

        }

        private void menu_item_open_Click(object sender, EventArgs e)
        {
            System.IO.Stream myStream = null;
            OpenFileDialog openFileDialog1 = new OpenFileDialog();

            openFileDialog1.Filter = "XML files (*.xml)|*.XML|CSM Map files|*.CSM";
            openFileDialog1.FilterIndex = 1;
            openFileDialog1.RestoreDirectory = true;
            openFileDialog1.InitialDirectory = System.IO.Directory.GetCurrentDirectory();

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    if ((myStream = openFileDialog1.OpenFile()) != null)
                    {
                        using (myStream)
                        {
                            XmlTextReader reader = new XmlTextReader(openFileDialog1.FileName); // xml 파일을 엽니다

                            while (reader.Read()) //xml 을 읽습니다.
                            {
                                switch (reader.LocalName) // 속성을 읽습니다.
                                {
                                    case "1": // thumbnail 이라는 속성이 있을때 다음 명령을 실행합니다.
                                        label1.Text = reader.ReadElementContentAsString();
                                        break;
                                    case "2": // total 이라는 속성이 있을경우 다음명령을 실행합니다.
                                        label2.Text = reader.ReadElementContentAsString();
                                        break;
                                }
                            }
                        }
                    }
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Error: Could not read file from disk. Original error: " + ex.Message);
                }
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
            contents.Size = new Size(contents.Size.Width, Screen.PrimaryScreen.Bounds.Height - minimap.Size.Height);

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
    }
}
