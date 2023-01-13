/*
==============================================================
Program to create custom php framework
This is a tiny php framework for BLog post. 
The basic idea for creating this framework is taken 
from the Laravel framework.
Language C++
Version: 1.0.0
==============================================================
*/

#include <iostream>
#include <chrono>
#include <thread>
#include <direct.h>
#include <string>
#include <fstream>
using namespace std;
#include "file_content.h"

class CreateProject {

    private:
        string project;
        ofstream File[10], RootFile[3], Data[10][6];
        static constexpr int  rootArr = 3;
        string rootfiles[rootArr] = {"/.env", "/global.css", "/index.php"};
        string folders[6] = {"/controller", "/database", "/includes", "/js", "/model", "/views"};
        static constexpr int  contrArr = 3;
        string contrFile[contrArr] = {"/login.contr.php", "/post.contr.php", "/signup.contr.php"};
        string seed = "/seeders";
        string seedFile = "/seeder.class.php";
        static constexpr int dbArr = 2;
        string dbFiles[dbArr] = {"/Dbh.class.php", "/maketables.class.php"};
        static constexpr int incArr = 6;
        string incFile[incArr] = {"/create.inc.php", "/delete.inc.php", "/edit.inc.php", "/login.inc.php", "/logout.inc.php", "/signup.inc.php"};
        static constexpr int jsArr = 1;
        string jsFile[jsArr] = {"/js.js"};
        static constexpr int modelArr = 3;
        string modelFile[modelArr] = {"/login.class.php", "/post.class.php", "/signup.class.php"};
        string layout = "/layouts";
        string layoutFile = "/header.php";
        static constexpr int viewArr = 6;
        string viewFile[viewArr] = {"/blog.php", "/create.php", "/edit.php", "/login.php", "/navigation.php", "/post.php"};

    public:
        void projectName() {

            cout << "\n###################################################\n";
            cout <<"            ___        ___   ___          ___     "<< endl;
            cout <<"    |    | |     |    |   | |   | |    | |        "<< endl;
            cout <<"    | /\\ | |___  |    |     |   | |\\  /| |__    "<< endl;
            cout <<"    |/  \\| |___  |___ |___| |___| | \\/ | |___   "<< endl;
            cout << "\n################################################### \n";
            cout << "***************************************************\n";
            cout << "   This is a custom php framework builder app!" << endl;
            cout << "***************************************************\n";
     
            cout <<"Enter the name of project!" << endl;
            cin >> project;

            if (mkdir(project.c_str()) == -1)
            {
                cout <<"Project folder: " << project <<" exists" << endl;
            }
            else
            {
                cout << "Project folder: " << project << " is created!" << endl;
            }
        }

        void createFolders() {

            for (int i = 0; i < 6; i++)
            {
                if (mkdir((project + folders[i]).c_str()) == -1)
                {

                    cout <<"Folder: " << folders[i] <<" exists" << endl;
                }
                else
                {
                    cout << "Folder: " << folders[i] << " is created! " << endl; 
                    
                    if (i == 0)
                    {  
                        createFolderFile( i, contrFile, contrArr);
                    }
                    else if (i == 1)
                    {
                        createSubFolders(i, seed);
                        createSubFolderFile( i, seed, seedFile, seedContent);
                        createFolderFile( i, dbFiles, dbArr);

                    }
                    else if (i == 2)
                    {
                        createFolderFile( i, incFile, incArr);
                       
                    }
                    else if (i == 3)
                    {
                        createFolderFile( i, jsFile, jsArr);
                       
                    }
                    else if (i == 4)
                    {
                        createFolderFile( i, modelFile, modelArr);
                    }
                    else if (i == 5)
                    {
                        createSubFolders(i, layout);
                        createSubFolderFile(i, layout, layoutFile, layoutContent); 
                        createFolderFile( i, viewFile, viewArr);
                       
                    }
                    
                }
            }   
            createFile(rootfiles, rootArr);
        }

        void createFile(string arr[], int size) {

            for (int i = 0; i < size; i++)
            {
                 RootFile[i].open(project + rootfiles[i], ios::in);
                if (!RootFile[i])
                {
                    RootFile[i].open(project + rootfiles[i], ios::app|ios::out);
                    RootFile[i] << rootContent[i];
                    cout <<"File: " << rootfiles[i] << " is created: " << endl;
                }
                else
                {
                cout <<"File: " << rootfiles[i] << " exists!" << endl;
                }
            }
        }

        void createFolderFile( int i, string file[], int size) {

            if (mkdir((project + folders[i]).c_str()) == -1)
            {
                for (int j = 0; j < size; j++)
                {   
                    Data[i][j].open(project + folders[i] + file[j], ios::in);

                    if (!Data[i][j])
                    {
                        Data[i][j].open(project + folders[i] + file[j], ios::app|ios::out);
                        Data[i][j] << "<?php \n\techo \"Hello World!\";  \n?>";
                        cout <<"File: " << folders[i] << file[j] << " is created: " << endl;
                    }
                    else
                    {
                        cout <<"File: " << folders[i] << file[j] <<" exists!" << endl;
                    }
                }
            }
        }

        void createSubFolders( int i, string subFolder) {
           
            if (mkdir((project + folders[i] + subFolder).c_str()) == -1)
            {
                cout <<"Folder: " << folders[i] << subFolder <<" exists" << endl;
            }
            else
            {
                cout << "Folder: " << folders[i] << subFolder << " is created! " << endl;
            }
        }

        void createSubFolderFile(  int i, string subFolder, string file, string content) {

            if (mkdir((project + folders[i] + subFolder).c_str()) == -1)
            {
                File[i].open(project + folders[i] + subFolder + file, ios::in);

                if (!File[i])
                {   
                    File[i].open(project + folders[i] + subFolder + file, ios::app|ios::out);
                    File[i] << content;
                    // File[i] << "<?php \n\techo \"Hello World!\";  \n?>";
                    cout << "File: " << folders[i] << subFolder << file << " is created! " << endl;
                }
                
                else
                {
                    cout << "File: " << folders[i] << subFolder << file << " exists: " << endl;
                }

            }

        }

};

int main() {  

    CreateProject project;
    project.projectName();
    project.createFolders();
    cout <<"Project is created! ";
    this_thread::sleep_for(chrono::milliseconds(5000));
    return 0;
}