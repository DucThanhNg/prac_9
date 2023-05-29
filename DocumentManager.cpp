#include "DocumentManager.h"


DocumentManager::Document::Document(std::string name, int id, int license_limit){
    this->name = name;
    this->id = id;
    this->license_limit = license_limit;
}

void DocumentManager::addPatron(int patronID){
    patrons.insert(patronID);
}

int DocumentManager::search(std::string name){
    if (name_to_docid.count(name) > 0){
        return name_to_docid[name];
    }
    else{
        return 0;
    }
}

void DocumentManager::addDocument(std::string name, int id, int license_limit){
    if (name_to_docid.count(name) == 0) {
            documents.emplace(id, Document(name, id, license_limit));
            name_to_docid[name] = id;
        }
}

bool DocumentManager::borrowDocument(int docid, int patronID){
    return true;
}

void DocumentManager:: returnDocument(int docid, int patronID){
    return;
}