{
using namespace std;

   TH1 *hi1 = new TH1D("hi1","Czas potrzebny na zamowienie i otrzymanie jedzenia on-line",100,10,110);
    double tab[10000];
    ifstream d;
    d.open("D:\\path...\\output.txt");
    for(int i=0;i<10000;++i)
		{
			d>>tab[i];
			hi1->Fill(tab[i]);
		}
    d.close();

	hi1->SetFillColor(20);
	hi1->SetFillStyle(3001);
	
    hi1->Draw();    
}
