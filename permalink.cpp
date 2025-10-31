#include<bits/stdc++.h>
#include<windows.h>
namespace fs=std::filesystem;
std::string wstring_to_utf8(const std::wstring& wstr){
    if(wstr.empty()) return "";
    int size_needed=WideCharToMultiByte(CP_UTF8,0,&wstr[0],(int)wstr.size(),NULL,0,NULL,NULL);
    std::string strTo(size_needed,0);
    WideCharToMultiByte(CP_UTF8,0,&wstr[0],(int)wstr.size(),&strTo[0],size_needed,NULL,NULL);
    return strTo;
}
std::string toPinyin(const std::string& name){
    std::string tmpfile="tmp_input.txt";
    std::ofstream fout(tmpfile,std::ios::binary);
    fout<<name;fout.close();
    std::string command="python -X utf8 -c "
    "\"from pypinyin import lazy_pinyin; import sys; "
    "text=open('tmp_input.txt',encoding='utf-8').read(); "
    "print('-'.join(lazy_pinyin(text)))\"";
    std::string result;
    char buffer[256];
    FILE* pipe=_popen(command.c_str(),"r");
    if(!pipe) return "";
    while(fgets(buffer,sizeof(buffer),pipe)) result+=buffer;
    _pclose(pipe);
    result.erase(std::remove(result.begin(),result.end(),'\n'),result.end());
    return result;
}
std::string normalize(std::string name){
    name=toPinyin(name);
    std::transform(name.begin(),name.end(),name.begin(),::tolower);
    std::replace(name.begin(),name.end(),' ','-');
    return std::regex_replace(name,std::regex("[^a-z0-9\\-]"),"");
}
bool hasFrontMatter(const std::string& content){
    return content.size()>=3&&content.substr(0,3)=="---";
}
int main(){
    system("chcp 65001 > nul");
    std::wstring folder=L"_blogs";
    for(const auto& entry: fs::directory_iterator(folder)){
        if(entry.path().extension()==L".md"){
            std::wstring wname=entry.path().stem().wstring();
            std::string name=wstring_to_utf8(wname),
            permalink="/blog/"+normalize(name)+"/";
            std::ifstream fin(entry.path());
            std::stringstream buffer;
            buffer<<fin.rdbuf();
            std::string content=buffer.str();
            fin.close();
            if(!hasFrontMatter(content)){
                std::string newContent="---\nlayout: default\ntitle: "+name+"\npermalink: "+permalink+"\n---\n\n"+content;
                std::ofstream fout(entry.path());
                fout<<newContent;
                fout.close();
                std::cout<<"Processed: "<<entry.path()<<"->"<<permalink<<'\n';
            }
        }
    }
}