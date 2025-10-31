#include<bits/stdc++.h>
namespace fs=std::filesystem;
std::string normalize(std::string name){
    std::transform(name.begin(),name.end(),name.begin(),::tolower);
    std::replace(name.begin(),name.end(),' ','-');
    return std::regex_replace(name,std::regex("[^a-z0-9\\-]"),"");
}
bool hasFrontMatter(const std::string& content){
    return content.size()>=3&&content.substr(0,3)=="---";
}
int main(){
    std::string folder="_blogs";
    for(const auto& entry: fs::directory_iterator(folder)){
        if(entry.is_regular_file()&&entry.path().extension()==".md"){
            std::string path=entry.path().string(),
            name=entry.path().stem().string(),
            permalink="/blog/"+normalize(name)+"/";
            std::ifstream fin(path);
            std::stringstream buffer;
            buffer<<fin.rdbuf();
            std::string content=buffer.str();
            fin.close();
            if(!hasFrontMatter(content)){
                std::string newContent="---\nlayout: default\ntitle: "+name+"\npermalink: "+permalink+"\n---\n\n"+content;
                std::ofstream fout(path);
                fout<<newContent;
                fout.close();
                std::cout<<"Processed: "<<path<<"->"<<permalink<<'\n';
            }
        }
    }
}