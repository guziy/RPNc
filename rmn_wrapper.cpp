

#include <iostream>

using namespace std;

 //associate file_name with the file number iun
 //I don't know what is x, but in the example it was 0
 // options = 'STD+RND' in the example
extern "C" int c_fnom(int* iun, char* file_name, char* options, int x );

extern "C" int c_fstouv(int iun,  char* options);


//for finding 2d lat/lons
extern "C" int  c_ezgdef_fmem(int ni, int nj, char* grtyp, char* e_l_s,
                                int ig1, int ig2, int ig3, int ig4,
                                float* lons, float* lats);

extern "C" int c_gdll(int ezgdef, float* lat_2d, float* lon_2d);


/*****************************************************************************
 *                        C _ F S T I N F                                    *
 *                                                                           *
 *Object                                                                     *
 *   Locate the next record that matches the research keys.                  *
 *                                                                           *
 *Arguments                                                                  *
 *                                                                           *
 *  IN  iun     unit number associated to the file                           *
 *  OUT ni      dimension 1 of the data field                                *
 *  OUT nj      dimension 2 of the data field                                *
 *  OUT nk      dimension 3 of the data field                                *
 *  IN  datev   valid date                                                   *
 *  IN  etiket  label                                                        *
 *  IN  ip1     vertical level                                               *
 *  IN  ip2     forecast hour                                                *
 *  IN  ip3     user defined identifier                                      *
 *  IN  typvar  type of field                                                *
 *  IN  nomvar  variable name                                                *
 *                                                                           *
 *****************************************************************************/

extern "C" int c_fstinf(int iun, int *ni, int *nj, int *nk, int datev,char *in_etiket,
                 int ip1, int ip2, int ip3, char *in_typvar, char *in_nomvar);


extern "C" void c_fstlir(float* buffer, int iun, int *ni, int *nj, int* nk,
                   int datev,  char* etiket, int ip1, int ip2, int ip3,
                    char* typvar,  char* nomvar);

/*****************************************************************************
 *                         C _ F S T F R M                                   *
 *                                                                           *
 *Object                                                                     *
 *   Closes a RPN standard file.                                             *
 *                                                                           *
 *Arguments                                                                  *
 *                                                                           *
 *  IN  iun     unit number associated to the file                           *
 *                                                                           *
 *****************************************************************************/
extern "C" int c_fstfrm(int iun);
extern "C" int c_fclos(int iun);


/*****************************************************************************
 *                         C _ F S T L U K                                   *
 *                                                                           *
 *Object                                                                     *
 *   Read the record at position given by handle.                            *
 *                                                                           *
 *Arguments                                                                  *
 *                                                                           *
 *  OUT field   data field to be read                                        *
 *  IN  handle  positioning information to the record                        *
 *  OUT ni      dimension 1 of the data field                                *
 *  OUT nj      dimension 2 of the data field                                *
 *  OUT nk      dimension 3 of the data field                                *
 *                                                                           *
 *****************************************************************************/

extern "C" int c_fstluk(float *field, int handle, int *ni, int *nj, int *nk);



/*****************************************************************************
 *                         C _ F S T S U I                                   *
 *                                                                           *
 *Object                                                                     *
 *   Finds the next record that matches the last search criterias            *
 *                                                                           *
 *Arguments                                                                  *
 *                                                                           *
 *  IN  iun     unit number associated to the file                           *
 *  OUT ni      dimension 1 of the data field                                *
 *  OUT nj      dimension 2 of the data field                                *
 *  OUT nk      dimension 3 of the data field                                *
 *                                                                           *
 *****************************************************************************/

int c_fstsui(int iun, int *ni, int *nj, int *nk);


/*****************************************************************************
 *                       C _ F S T P R M                                     *
 *                                                                           *
 *Object                                                                     *
 *   Get all the description informations of the record.                     *
 *                                                                           *
 *Rev 001 - M. Lepine - Oct 2002, returns extra1 as the validity datestamp   *
 *                                                                           *
 *Arguments                                                                  *
 *                                                                           *
 *  IN  handle  positioning information to the record                        *
 *  OUT date    date time stamp                                              *
 *  OUT deet    length of a time step in seconds                             *
 *  OUT npas    time step number                                             *
 *  OUT ni      first dimension of the data field                            *
 *  OUT nj      second dimension of the data field                           *
 *  OUT nk      third dimension of the data field                            *
 *  OUT nbits   number of bits kept for the elements of the field            *
 *  OUT datyp   data type of the elements                                    *
 *  OUT ip1     vertical level                                               *
 *  OUT ip2     forecast hour                                                *
 *  OUT ip3     user defined identifier                                      *
 *  OUT typvar  type of field (forecast, analysis, climatology)              *
 *  OUT nomvar  variable name                                                *
 *  OUT etiket  label                                                        *
 *  OUT grtyp   type of geographical projection                              *
 *  OUT ig1     first grid descriptor                                        *
 *  OUT ig2     second grid descriptor                                       *
 *  OUT ig3     third grid descriptor                                        *
 *  OUT ig4     fourth grid descriptor                                       *
 *  OUT swa     starting word address                                        *
 *  OUT lng     record length                                                *
 *  OUT dltf    delete flag                                                  *
 *  OUT ubc     unused bit count                                             *
 *  OUT extra1  extra parameter                                              *
 *  OUT extra2  extra parameter                                              *
 *  OUT extra3  extra parameter                                              *
 *                                                                           *
 *****************************************************************************/

extern "C" int c_fstprm(int handle,
             int *dateo, int *deet, int *npas,
             int *ni, int *nj, int *nk,
             int *nbits, int *datyp, int *ip1,
             int *ip2, int *ip3, char *typvar,
             char *nomvar, char *etiket, char *grtyp,
             int *ig1, int *ig2, int *ig3,
             int *ig4, int *swa, int *lng,
             int *dltf, int *ubc, int *extra1,
             int *extra2, int *extra3);


/*****************************************************************************
 *                          C _ I P 1 _ A L L                                *
 *                                                                           *
 *Object                                                                     *
 *   Generates all possible coded ip1 values for a given level               *
 *                                                                           *
 *Arguments                                                                  *
 *                                                                           *
 *  IN  level          ip1 level (float value)                               *
 *  IN  kind           level kind as defined in convip                       *
 *                                                                           *
 *****************************************************************************/

extern "C" int c_ip1_all(float level, int kind);


////////////////////////////////////////////////////////////////////////////////
//wrapper functions
extern "C" int fnom_wrapper(int* iun, char *file_name, char *options, int x){
    return c_fnom(iun, file_name, options, x );
}

extern "C" int fstouv_wrapper(int iun,  char* options){
    return c_fstouv( iun, options);
}

//gets a key of the field to find it in a file
extern "C" int fstinf_wrapper(int iun, int *ni, int *nj, int *nk, int datev,char *in_etiket,
                 int ip1, int ip2, int ip3, char *in_typvar, char *in_nomvar){
    int key;
    key = c_fstinf(iun, ni, nj, nk, datev, in_etiket, ip1, ip2, ip3, in_typvar, in_nomvar);
    return key;
}




extern "C" int fstluk_wrapper(float *field, int handle, int *ni, int *nj, int *nk){
    return c_fstluk(field, handle, ni, nj, nk);
}

extern "C" int fstprm_wrapper(int handle,
             int *dateo, int *deet, int *npas,
             int *ni, int *nj, int *nk,
             int *nbits, int *datyp, int *ip1,
             int *ip2, int *ip3, char *typvar,
             char *nomvar, char *etiket, char *grtyp,
             int *ig1, int *ig2, int *ig3,
             int *ig4, int *swa, int *lng,
             int *dltf, int *ubc, int *extra1,
             int *extra2, int *extra3){
    return c_fstprm(handle, dateo, deet, npas,
             ni, nj, nk,
             nbits, datyp, ip1,
             ip2, ip3, typvar,
             nomvar, etiket, grtyp,
             ig1, ig2, ig3,
             ig4, swa, lng,
             dltf, ubc, extra1,
             extra2, extra3);
}


extern "C" void fstlir_wrapper(float* buffer, int iun, int *ni, int *nj, int* nk,
                   int datev,  char* etiket, int ip1, int ip2, int ip3,
                    char* typvar,  char* nomvar){
    c_fstlir(buffer, iun, ni, nj, nk,
                  datev, etiket, ip1, ip2, ip3,
                  typvar, nomvar);
}

/**
 *
 * @param level
 * @param kind
 * @return ip coded level
 *
 * Ouput:    IP  =   Valeur codee
*            P    =   Valeur reelle
*               KIND =0, p est en hauteur (m) par rapport au niveau de la mer (-20,000 -> 100,000)
*               KIND =1, p est en sigma                                       (0.0 -> 1.0)
*               KIND =2, p est en pression (mb)                               (0 -> 1100)
*               KIND =3, p est un code arbitraire                             (-4.8e8 -> 10e10)
*               KIND =4, p est en hauteur (M) par rapport au niveau du sol    (-20,000 -> 100,000)
*               KIND =5, p est en coordonnee hybride                          (0.0 -> 1.0)
*               KIND =6, p est en coordonnee theta                            (1 -> 200,000)
*               KIND =10, p represente le temps en heure                      (0.0 -> 200,000.0)
*               KIND =15, reserve (entiers)
*               KIND =17, p represente l'indice x de la matrice de conversion (1.0 -> 1.0e10)
*               KIND =21, p est en metres-pression  (partage avec kind=5 a cause du range exclusif)
*                                                                             (0 -> 1,000,000) fact=1e4
 */
extern "C" int ip1_all_wrapper(float level, int kind){
    return c_ip1_all(level, kind);
}


/**
 * gets code of the crs to find 2d lat/lon fields
 * @param ni
 * @param nj
 * @param grtyp
 * @param e_l_s
 * @param ig1
 * @param ig2
 * @param ig3
 * @param ig4
 * @param lons
 * @param lats
 * @return
 */
extern "C" int  ezgdef_fmem_wrapper(int ni, int nj, char* grtyp, char* e_l_s,
                                int ig1, int ig2, int ig3, int ig4,
                                float* lons, float* lats){
    return c_ezgdef_fmem(ni, nj, grtyp,e_l_s, ig1, ig2, ig3, ig4,
                         lons, lats);
}

/**
 *
 * @param ezgdef
 * @param lats_2d - output
 * @param lons_2d - output
 * @return error code, if >= 0, all is ok
 */
extern "C" int gdll_wrapper(int ezgdef, float* lats_2d, float* lons_2d){
    int ier = c_gdll(ezgdef, lats_2d, lons_2d);
    return ier;
}


/**
 * close rpn file
 * @param iun
 * @return
 */
extern "C" int fstfrm_wrapper(int iun){
    return c_fstfrm(iun);
}

/**
 * close rpn file
 * @param iun
 * @return
 */
extern "C" int fclos_wrapper(int iun){
    return c_fclos(iun);
}


extern "C" char* get_message(){
    return "hello world";
}

extern "C" int get_number(){
    return 5;
}
