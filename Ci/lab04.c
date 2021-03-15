#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
main()
{
	pid_t pid;
	int rv;
	switch(pid=fork()) {
	case -1:
	perror("fork"); /* произошла ошибка */
exit(1); /*выход из родительского процесса*/
case 0:
printf(" CHILD: Это процесс-потомок!\n");
printf(" CHILD: Мой PID -- %d\n", getpid());
printf(" CHILD: PID моего родителя -- %d\n",
 getppid());
printf(" CHILD: Введите мой код возврата
(как можно меньше):");
scanf(" %d");
printf(" CHILD: Выход!\n");
exit(rv);
default:
printf("PARENT: Это процесс-родитель!\n");
printf("PARENT: Мой PID -- %d\n", getpid());
printf("PARENT: PID моего потомка %d\n",pid);
printf("PARENT: Я жду, пока потомок
не вызовет exit()...\n");
wait();
printf("PARENT: Код возврата потомка:%d\n",
WEXITSTATUS(rv));
printf("PARENT: Выход!\n");
}
}
 /*
}
char** Splitting(char* strIn, int& iCntWord) 
{
    // Считаем количество слов по пробелам и длинну строки
    int cnt = 0;
    int i = 0;
    int flag = 0;
    for (i; strIn[i] != 0; i++)
    {
        if (strIn[i] == ' ')
        {
            cnt++;
            flag = 0;
        }
        else
            flag = 1;
    }
    flag ? iCntWord = cnt + 1 : iCntWord = cnt;
    char * buf = new char[i+1];
    char  ** adres = new char*[iCntWord];
    cnt = 0;
    adres[cnt] = buf;
    for (int j = 0; j<i+1; j++)
        
        if (strIn[j] == ' ')
        {
            buf[j] = 0;
            adres[++cnt] = &buf[j + 1];
        }
        else
        {
            buf[j] = strIn[j];
        }
    
 
 
     
     return adres;
}
 
void main()
{
    setlocale(LC_ALL, "ru-RU");
    char * str = "Это тестовая строка для проверки  работы функции";
    int q = 0;
    char **c; 
    c = Splitting(str, q);
    for (int i = 0; i < q; i++)
        std::cout << c[i] << std::endl;
    delete[] c;
    system("Pause");
}%                
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
using namespace std;
 
int main()
{
    vector<string> vstr;
        string str = "Hello My World!!!";
     
        while(str != "")
        {
            int space_pos = str.find(' ');
            if(space_pos != -1)
            {
                vstr.push_back(str.substr(0, space_pos));
                str.erase(0, space_pos + 1);
            }
            else
            {
                vstr.push_back(str);
                str.clear();
            }
        }
     
        for(int i = 0; i < vstr.size(); i++)
        cout << vstr[i] << endl;
     
    const ;
    string buf[vstr.size()] = vstr;
    ofstream fout("output.txt");
 
    for (int b1 = 1; b1 <= vstr.size(); ++b1)
    {
        for (int b2 = 1; b2 <= vstr.size(); ++b2)
        {
            int count = 0;
 
            for (int i = 1; i < vstr.size(); ++i)
            {
                if (buf[i - 1] == buf[b1] && buf[i] == buf[b2])
                    ++count;
            }
 
            if (count != 0)
            {
                cout << '[' << b1 << ", " << b2 << "]: " << count << endl;
                fout << '[' << b1 << ", " << b2 << "]: " << count << endl;
            }
        }
    }
 
    fout.close();
 
    system("pause");
    return 0;
}%            */    