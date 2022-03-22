struct Icon {
    char* Image;
    char* Text;
    int x;
    int y;
};

int readXml();
char* readNodeContent(int icon);
char* readNodeAtribute(int icon, int atributeIcon);
int ReadTotalIcons();
struct Icon ReadIcon(int Icon);