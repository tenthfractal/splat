/*
  Parameters for 1 arc-second high resolution mode of operation
  Generated by ./configure by watkinsp on Wed Jun 17 08:31:02 PDT 2015
*/
#define HD_MODE 1
#define MAXPAGES 64

#if HD_MODE==0
#if MAXPAGES==4
#define ARRAYSIZE 4950
#endif

#if MAXPAGES==9
#define ARRAYSIZE 10870
#endif

#if MAXPAGES==16
#define ARRAYSIZE 19240
#endif

#if MAXPAGES==25
#define ARRAYSIZE 30025
#endif

#if MAXPAGES==36
#define ARRAYSIZE 43217
#endif

#if MAXPAGES==49
#define ARRAYSIZE 58813
#endif

#if MAXPAGES==64
#define ARRAYSIZE 76810
#endif

#define IPPD 1200
#endif

#if HD_MODE==1
#if MAXPAGES==1
#define ARRAYSIZE 5092
#endif

#if MAXPAGES==4
#define ARRAYSIZE 14844
#endif

#if MAXPAGES==9
#define ARRAYSIZE 32600
#endif

#if MAXPAGES==16
#define ARRAYSIZE 57713
#endif

#if MAXPAGES==25
#define ARRAYSIZE 90072
#endif

#if MAXPAGES==36
#define ARRAYSIZE 129650
#endif

#if MAXPAGES==49
#define ARRAYSIZE 176437
#endif

#if MAXPAGES==64
#define ARRAYSIZE 230430
#endif

#define IPPD 3600
#endif

#define EARTHRADIUS 20902230.97
#define DEG2RAD 1.74532925199e-02
#define	METERS_PER_MILE 1609.344
#define METERS_PER_FOOT 0.3048
#define	KM_PER_MILE 1.609344
#define FOUR_THIRDS 1.3333333333333

struct site {	double lat;
    double lon;
    float alt;
    char name[50];
    char filename[255];
};

struct path {	double lat[ARRAYSIZE];
    double lon[ARRAYSIZE];
    double elevation[ARRAYSIZE];
    double distance[ARRAYSIZE];
    int length;
};

struct dem {	int min_north;
    int max_north;
    int min_west;
    int max_west;
    int max_el;
    int min_el;
    short data[IPPD][IPPD];
    unsigned char mask[IPPD][IPPD];
    unsigned char signal[IPPD][IPPD];
};

struct LR {	double eps_dielect;
    double sgm_conductivity;
    double eno_ns_surfref;
    double frq_mhz;
    double conf;
    double rel;
    double erp;
    int radio_climate;
    int pol;
    float antenna_pattern[361][1001];
};

extern char splat_version[6];
const size_t SPLAT_VERSION_SIZE = sizeof(splat_version);

extern char splat_name[10];
const size_t SPLAT_NAME_SIZE = sizeof(splat_name);

extern char dashes[80];
const size_t DASHES_SIZE = sizeof(dashes);

extern char sdf_path[255];
const size_t SDF_PATH_SIZE = sizeof(sdf_path);

extern char olditm, gpsav;
extern unsigned char dbm, metric, smooth_contours;
extern int contour_threshold, ippd, mpi;
extern double clutter, forced_erp, forced_freq, fzone_clearance, earthradius, ppd, dpp, max_range;

extern struct path *path;
//extern struct dem *dem;
extern struct LR *LR;


struct site LoadQTH(char *filename);
char ReadLRParm(struct site txsite, char forced_read);
void PlaceMarker(struct site location, dem dem[]);

void WritePPM(char *filename, unsigned char geo, unsigned char kml, unsigned char ngs, struct site *xmtr, unsigned char txsites, dem dem[]);
void WritePPMLR(char *filename, unsigned char geo, unsigned char kml, unsigned char ngs, struct site *xmtr, unsigned char txsites, dem dem[]);
void WritePPMDBM(char *filename, unsigned char geo, unsigned char kml, unsigned char ngs, struct site *xmtr, unsigned char txsites, dem dem[]);
void WritePPMSS(char *filename, unsigned char geo, unsigned char kml, unsigned char ngs, struct site *xmtr, unsigned char txsites, dem dem[]);
double LonDiff(double lon1, double lon2);
int LoadANO(char *filename, dem dem[]);
void LoadBoundaries(char *filename, dem dem[]);
void LoadCities(char *filename, dem dem[]);
void LoadTopoData(int max_lon, int min_lon, int max_lat, int min_lat, dem dem[]);
void LoadUDT(char *filename, dem dem[]);
double GetElevation(struct site location, dem dem[]);
void WriteKML(struct site source, struct site destination, dem dem[]);
void PathReport(struct site source, struct site destination, char *name, char graph_it, double elev[], dem dem[]);
void SiteReport(struct site xmtr, dem dem[]);
void GraphTerrain(struct site source, struct site destination, char *name, dem dem[]);
void GraphElevation(struct site source, struct site destination, char *name, dem dem[]);
void GraphHeight(struct site source, struct site destination, char *name, unsigned char fresnel_plot, unsigned char normalized, dem dem[]);
void PlotLOSMap(struct site source, double altitude, dem dem[]);
void PlotLRMap(struct site source, double altitude, char *plo_filename, double elev[], dem dem[]);
void PlotPath(struct site source, struct site destination, char mask_value, dem dem[]);