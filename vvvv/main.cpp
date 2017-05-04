#include <string>
#include <iostream>
using namespace std;

class CDeskTop
{

public:
    void SetRAM(const string& sRAM)                 { m_sRAM = sRAM;                 }
    void SetProcessor(const string& sProcessor)     { m_sProcessor = sProcessor;     }
    void SetMotherBoard(const string& sMotherBoard) { m_sMotherBoard = sMotherBoard; }
    void SetMonitor(const string& sMonitor)         { m_sMonitor = sMonitor;         }
    void SetKeyboard(const string& sKeyboard)       { m_sKeyboard = sKeyboard;       }
    void SetMouse(const string& sMouse)             { m_sMouse = sMouse;             }
    void SetSpeaker(const string& sSpeaker)         { m_sSpeaker = sSpeaker;         }

    void Start() {
        cout<<"Starting the Computer With the Config:\n";
        cout<<"RAM:"<<m_sRAM<<"\n";
        cout<<"Processor:"<<m_sProcessor<<"\n";
        cout<<"MotherBoard:"<<m_sMotherBoard<<"\n";
        cout<<"Monitor:"<<m_sMonitor<<"\n";
        cout<<"Keyboard:"<<m_sKeyboard<<"\n";
        cout<<"Mouse:"<<m_sMouse<<"\n";
        cout<<"Speaker:"<<m_sSpeaker<<"\n";
    }

private:
    string m_sMonitor;
    string m_sKeyboard;
    string m_sMouse;
    string m_sSpeaker;
    string m_sRAM;
    string m_sProcessor;
    string m_sMotherBoard;
};

class IDeskTopBuilder
{
public:
    virtual ~ IDeskTopBuilder() {}
    CDeskTop* GetDeskTop() { return m_pDeskTop; }
    void CreateNewDeskTop()  { m_pDeskTop = new CDeskTop(); }
    virtual void BuidMonitor()      = 0;
    virtual void BuildKeyBoard()    = 0;
    virtual void BuidMouse()        = 0;
    virtual void BuildRAM()         = 0;
    virtual void BuidProcessor()    = 0;
    virtual void BuidSpeaker()      = 0;
    virtual void BuildMotherBoard() = 0;
private:
    string m_sRAM;
    string m_sProcessor;
    string m_sMotherBoard;
    string m_sMonitor;
    string m_sKeyboard;
    string m_sMouse;
    string m_sSpeaker;
protected:
    CDeskTop* m_pDeskTop;
};

class DellDeskTopBuilder : public IDeskTopBuilder
{
public:
    void BuidMonitor()      { m_pDeskTop->SetMonitor("Dell Monitor"); }
    void BuildKeyBoard()    { m_pDeskTop->SetKeyboard("Dell Keyboard"); }
    void BuidMouse()        { m_pDeskTop->SetMouse("Dell Mouse");}
    void BuildRAM()         { m_pDeskTop->SetRAM("Hynet DDR3 ");}
    void BuidProcessor()    { m_pDeskTop->SetProcessor("Intel I6");}
    void BuidSpeaker()      { m_pDeskTop->SetSpeaker("Dell Speaker");}
    void BuildMotherBoard() { m_pDeskTop->SetMotherBoard("Gigabyte");}
};

class AcerDeskTopBuilder : public IDeskTopBuilder
{
public:
    void BuidMonitor()      { m_pDeskTop->SetMonitor("Acer Monitor"); }
    void BuildKeyBoard()    { m_pDeskTop->SetKeyboard("Acer Keyboard"); }
    void BuidMouse()        { m_pDeskTop->SetMouse("Acer Mouse");}
    void BuildRAM()         { m_pDeskTop->SetRAM("Hynet DDR3 ");}
    void BuidProcessor()    { m_pDeskTop->SetProcessor("Intel I6");}
    void BuidSpeaker()      { m_pDeskTop->SetSpeaker("Acer Speaker");}
    void BuildMotherBoard() { m_pDeskTop->SetMotherBoard("Gigabyte");}
};

class ComputerShopDirector
{
public:
 void SetDeskTopBuilder(IDeskTopBuilder* pBuilder) { m_pBuilder = pBuilder;           }
 CDeskTop* GetDeskTop()                            { return m_pBuilder->GetDeskTop(); }

 void BuildDesktop(){
     m_pBuilder->CreateNewDeskTop();
     m_pBuilder->BuidMonitor();
     m_pBuilder->BuidMouse();
     m_pBuilder->BuildRAM();
     m_pBuilder->BuidProcessor();
     m_pBuilder->BuildKeyBoard();
     m_pBuilder->BuidSpeaker();
     m_pBuilder->BuildMotherBoard();
 }

private:
    IDeskTopBuilder* m_pBuilder;
};

//client

int main(){
    ComputerShopDirector director;
    IDeskTopBuilder* pBuilder = new AcerDeskTopBuilder();
    director.SetDeskTopBuilder(pBuilder);
    director.BuildDesktop();
    CDeskTop* pDeskTop = director.GetDeskTop();
    pDeskTop->Start();
    cout<<endl<<endl;
    pBuilder = new DellDeskTopBuilder();
    director.SetDeskTopBuilder(pBuilder);
    director.BuildDesktop();
    pDeskTop = director.GetDeskTop();
    pDeskTop->Start();
}
