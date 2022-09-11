#include "utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef  __linux__
#include <unistd.h>
#elif _WIN32
#include <Windows.h>
#endif


const int primes[] = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
    31, 37, 41, 47, 53, 59, 61, 67, 71,
    73, 79, 83, 89, 97, 101, 103, 107,
    109, 113, 127, 131, 137, 139, 149, 151,
};

int isprime(int val)
{
    if(val == 0 || val == 1)
        return 0;

    if(val % 2 == 0)
        return val == 2;

    if(val % 3 == 0)
        return val == 3;

    if(val % 5 == 0)
        return val == 5;

    for(int k = 7; k * k <= val; k += 2)
        if(val % k == 0)
            return 0;

    return 1;
}

int ndigit(int val)
{
    if(val == 0)
        return 1;

    int digit_count = 0;

    while (val) {
        ++digit_count;
        val /= 10;
    }

    return digit_count;
}

void dashline()
{
    printf("\n-------------------------------------------------------------------------------\n");
}

void xSleep(double sec)
{
#ifdef __linux__
    sleep((double)sec * 1000);
#elif _WIN32
    Sleep((double)sec * 1000);
#endif
}

void randomize()
{
    srand((unsigned)time(NULL));
}


void set_array_random(int *p, size_t size)
{
    while (size--){
        *p++ = rand() % 1000;
    }
}


void print_array(const int *p, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        if(i && i % 20 == 0)
            printf("\n");
        printf("%3d ", p[i]);
    }

   // dashline();
    printf("\n");
}


void sgets(char *p)
{
    int c;

    while ((c = getchar()) != '\n') {
        *p++ = (char )c;
    }

    *p = '\0';
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_str(const char *p)
{
    //ikiside aynı ifade
    //while(*p != '\0') {
    while(*p) {
        printf("%c ", *p++);
    }
    putchar('\n');
}

void gswap(void *vp1, void *vp2, size_t n)
{
    char *p1 = (char *)vp1;
    char *p2 = (char *)vp2;

    while (n--) {
        char temp = *p1;
        *p1++ = *p2;
        *p2++ = temp;
    }
}

//internal linkage
static int icmp(const void *vp1, const void *vp2)
{
    if(*(const int *)vp1 > *(const int *)vp2)
        return 1;

    if(*(const int *)vp1 < *(const int *)vp2)
        return -1;

    return 0;
}

void sort_array(int *p, size_t size)
{
    qsort(p, size, sizeof (*p), &icmp);
}


void clear_input_buffer(void)
{
    int c;

    while((c = getchar()) != '\n' && c != EOF)
        ;
}

void sleep(int millisecond)
{
    clock_t start = clock();

    while (1) {
        clock_t newclock = clock();
        if((double)(newclock - start) / CLOCKS_PER_SEC * 1000 > millisecond)
            return;
    }
}


const char * random_name(void)
{
    const char* const pnames[] = {
        "abdi", "abdullah", "abdulmuttalip", "adem", "adnan", "afacan", "agah", "ahmet", "akin", "alev",
"ali", "alican", "alparslan", "anil", "arda", "asim", "askin", "aslican", "aslihan", "ata",
"atakan", "atalay", "atif", "atil", "aycan", "aydan", "aykut", "ayla", "aylin", "aynur",
"ayse", "aytac", "aziz", "azize", "azmi", "baran", "bekir", "belgin", "bennur", "beril",
"berivan", "berk", "beste", "beyhan", "bilal", "bilge", "bilgin", "billur", "binnaz", "binnur",
"birhan", "bora", "bulent", "burak", "burhan", "busra", "cahide", "cahit", "can", "canan",
"candan", "caner", "cansu", "cebrail", "celal", "celik", "cem", "cemal", "cemil", "cemile",
"cemre", "cengiz", "cesim", "cetin", "ceyda", "ceyhan", "ceyhun", "ceylan", "cezmi", "cihan",
"cihat", "ciler","cumhur", "cuneyt", "demet", "demir", "deniz", "derin", "derya", "devlet", "devrim", "diana",
"dilber", "dilek", "dogan", "dost", "durmus", "durriye", "ece", "eda", "edip", "ediz",
"efe", "efecan", "ege", "egemen", "emine", "emirhan", "emre", "emrecan", "enes", "engin",
"ercument", "erdem", "esen", "esin", "esra", "eylul", "fadime", "fahri", "fazilet", "feramuz",
"feraye", "ferhat", "ferhunde", "figen", "fikret", "fuat", "fugen", "furkan", "galip", "garo",
"gazi", "gizem", "gul", "gulden", "gulsah", "gulsen", "gunay", "gurbuz", "gursel", "hakan",
"hakki", "haldun", "halime", "haluk", "handan", "hande", "handesu", "hasan", "helin", "hikmet",
"hilal", "hilmi", "hulki", "hulusi", "hulya", "huseyin", "iffet", "irmak", "ismail", "izzet",
"jade", "julide", "kaan", "kamil", "kamile", "kasim", "kaya", "kayahan", "kayhan", "kazim",
"kelami", "kenan", "kerem", "kerim", "keriman", "kezban", "korhan", "kunter", "kurthan", "lale",
"lamia", "leyla", "mahir", "malik", "mehmet", "melek", "melih", "melike", "melisa", "menekse", "mert",
"metin", "nucahit", "muhsin", "mukerrem", "murat", "murathan", "muruvvet", "muslum", "mustafa", "muzaffer", "naci", "naciye",
"nagehan", "nahit", "nalan", "nasrullah", "naz", "nazif", "nazife", "nazli", "necmettin", "necmi",
"necmiye", "nedim", "nefes", "nevsin", "nihal", "nihat", "nisan", "niyazi", "nurdan", "nuri",
"nuriye", "nurullah", "nusret", "okan", "olcay", "onat", "orkun", "osman", "pakize", "papatya",
"pelin", "pelinsu", "perihan", "petek", "pinat", "polat", "polathan", "poyraz", "recep", "refik",
"refika", "rumeysa", "rupen", "saadet", "sabriye", "sade", "sadegul", "sadettin", "sadi", "sadiye",
"sadri", "sadullah", "samet", "sami", "saniye", "sarp", "sefa", "sefer", "selenay", "selin",
"semsit", "sevda", "sevilay", "sevim", "seyhan", "sezai", "sezen", "sezer", "sidre", "sinem",
"soner", "su", "suheyla", "suleyman", "sumeyye", "suphi", "taci", "taner", "tanju", "tansel",
"tansu", "tarcan", "tarik", "tarkan", "tayfun", "tayyar", "tayyip", "tekin", "temel", "teoman",
"teslime", "tevfik", "tijen", "tonguc", "tufan", "tugay", "tugra", "tunc", "tuncer", "turgut",
"turhan", "ufuk", "ugur", "umit", "utku", "yalcin", "yasar", "yasemin", "yasin",
"yavuz", "yelda", "yeliz", "yesim", "yilmaz", "yunus", "yurdagul", "yurdakul", "yurdanur", "yusuf",
"zahide", "zahit", "zarife", "zekai", "zeliha", "zerrin", "ziya", "zubeyde", };

    return relem(pnames);
}
//--------------------------------------------------
//--------------------------------------------------
const char * random_surname(void)
{
    static const char* const pfnames[] = {
    "acar", "acgoze", "acuka", "ademoglu", "adiguzel", "agaoglu", "akarsu", "akcalar", "akgunes", "akkay",
    "akkuyu", "aklikit", "aksakal", "akyildiz", "akyoldas", "alemdar", "alniacik", "altindag", "altinisik", "altinorak",
    "arcan", "aslan", "avci", "aybeyaz", "aylak", "azmak", "bahceli", "bakirci", "baklavaci", "barutcu",
    "baturalp", "bayraktar", "bekar", "belgeli", "beyaz", "bilgic", "bozkaya", "boztas", "canbay", "candamar",
    "cangoz", "cankoc", "canlikaya", "cansever", "cansiz", "celik", "celiker", "cengaver", "cevikkol", "cilingir",
    "comakci", "corbaci", "cubukay", "cuhadar", "daglarca", "damar", "degirmenci", "demirdogen", "demirel", "derin",
    "dingin", "dokmeci", "dokuzcan", "dosteli", "dumbuk", "dunyalik", "ecevit", "edepli", "edepsiz", "efelik",
    "elebasi", "eliagir", "elibol", "elitemiz", "elkizi", "elmali", "eloglu", "emirkulu", "engerek", "engereke",
    "erdogan", "ergin", "erim", "ersoy", "ertakan", "esbereli", "esnedur", "esteberli", "etci", "ezergecer",
    "fakir", "fedai", "fincan", "firatonu", "fitrat", "gamsiz", "gedik", "geldik", "gilgamis", "girik",
    "girit", "gucsuz", "gultekin", "gumus", "gurkas", "hamsikoylu", "harmanci", "haselici", "hepguler", "hurmaci",
    "iliksiz", "issiz", "jilet", "kabasakal", "kadersiz", "kahraman", "kalemsiz", "kalinkas", "kalpsiz", "kalpten",
    "kapan", "kapici", "kaplan", "kara", "karabatur", "karaduman", "karaelmas", "karakis", "karakoyun", "karakuzu",
    "karamuk", "karaorman", "karasaban", "karataban", "karayel", "kayabasi", "kazanci", "kecisakal", "kelepce", "kelleci",
    "keskin", "kesman", "kilicdar", "kilimci", "kilinc", "kirboga", "kirci", "kocyigit", "kolcak", "komcu",
    "komurcu", "konak", "konca", "koralp", "korukcu", "kosnuk", "kotek", "koylu", "kucukkaya", "kulaksiz",
    "kurban", "kurtulus", "kusmen", "lalezar", "lokmaci", "lombak", "lufer", "maganda", "malazgirt", "malkaciran",
    "mazgirt", "merdane", "mertek", "merzifon", "mirza", "miskin", "miskinoglu", "muglali", "nazik", "nurtopu",
    "olmez", "oltu", "onaran", "ongun", "ordulu", "orhancan", "ormanci", "ortaca", "osmaneli", "otaci",
    "ovacik", "oztoklu", "ozvezneci", "pakdamar", "pirlanta", "polatkan", "portakal", "poturgeli", "reis", "renacan",
    "resimci", "saferikli", "safkan", "salca", "saldiray", "sallabas", "samanci", "saricakir", "sarikafa", "sarpdemir",
    "savaskan", "sefiloglu", "selercan", "semiz", "sener", "serce", "serinsun", "sessiz", "silahdar", "silifkeli",
    "simsek", "sivri", "sofuoglu", "sonmez", "sonuzun", "soylu", "soysalan", "soyubozuk", "sucu", "sulugoz",
    "supuren", "takes", "tamgun", "tamirci", "tantana", "tarumar", "tekinalp", "tekkaya", "tekkilic", "telek",
    "temiz", "temizel", "temizkalp", "tepecik", "tepsici", "tercan", "terlemez", "tertemiz", "tilki", "tokatci",
    "tombeki", "topatan", "topkapi", "tozkoporan", "tufancan", "tunali", "tuzcu", "tuztas", "ufurukcu", "ugursuz",
    "ulakci", "uluocak", "umutsuz", "unalan", "unalmis", "unkapani", "uraz", "uslu", "uyar", "uzay",
    "uzunadam", "yagizeli", "yanardag", "yanardoner", "yangin", "yaracan", "yaradan", "yarma", "yasayavas", "yasli",
    "yasmak", "yavas", "yavasakan", "yaygara", "yelden", "yeldirme", "yeldirmen", "yersiz", "yikilmaz", "yildirim",
    "yilgin", "yilmaz", "yolyapan", "yorganci", "yorgun", "yosun", "yurdakul", "yurekli", "yurekyakan", "yurtsuz",
    "zaimoglu", "zalim", "zengin", "zebani"
    };

    return relem(pfnames);
}
//--------------------------------------------------
//--------------------------------------------------
const char * random_town(void)
{
    static const char* const ptowns[] = {
"izmir", "afyonkarahisar", "kilis", "bolu", "yalova", "giresun", "tunceli", "manisa", "cankiri", "canakkale",
"mugla", "isparta", "ankara", "kahramanmaras", "nigde", "kirklareli", "artvin", "kirikkale", "bursa", "bingol",
"sirnak", "erzincan", "gaziantep", "bayburt", "tekirdag", "kocaeli", "trabzon", "ardahan", "elazig", "karabuk",
"samsun", "malatya", "aksaray", "van", "kars", "amasya", "kirsehir", "balikesir", "eskisehir", "sanliurfa",
"adiyaman", "mardin", "bilecik", "hakkari", "mus", "kayseri", "agri", "sinop", "istanbul", "mersin",
"aydin", "sivas", "yozgat", "igdir", "sakarya", "burdur", "antalya", "osmaniye", "konya", "tokat",
"zonguldak", "corum", "batman", "adana", "usak", "denizli", "edirne", "karaman", "ordu", "diyarbakir",
"siirt", "kutahya", "bitlis", "bartin", "nevsehir", "rize", "kastamonu", "duzce", "erzurum", "gumushane",
"hatay", };


    return relem(ptowns);
}




