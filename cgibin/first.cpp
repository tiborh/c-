#include <iostream>
using namespace std;
 
int main ()
{
    
   cout << "Content-type:text/html\r\n\r\n";
   cout << "<html>\n";
   cout << "<head>\n";
   cout << "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />\n";
   cout << "<title>今日は！初CGIプログラム</title>\n";
   cout << "</head>\n";
   cout << "<body>\n";
   cout << "<h1>今日は！</h1>\n";
   cout << "<h2>初（はつ）〜C++〜CGI〜プログラム</h2>\n";
   cout << "</body>\n";
   cout << "</html>\n";
   
   return 0;
}
