#include "Dict.h"

CDict::CDict()
{
	OpenDict();
}

CDict::~CDict()
{
	mapDict.clear();
}

void CDict::OpenDict()
{
	FILE *fpDict;
	if ((fpDict = fopen("words.dict", "r")) == NULL) {
		cout <<"can not open words.dict"<<endl;
		exit(1);
	}
  
	int id, freq;
	char word[16];
	while (fscanf(fpDict, "%s",  word) != EOF) {
		//cout<<word<<endl;
		mapDict.insert(map<string,int>::value_type (word, 0));
	}
	fclose(fpDict);
}

bool CDict::IsWord(string& str) const
{
	if (mapDict.find(str) != mapDict.end())
		return true;
	return false;
}
