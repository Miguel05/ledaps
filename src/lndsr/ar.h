#ifndef AR_H
#define AR_H

#include "lndsr.h"
#include "bool.h"
#include "lut.h"
#include "sixs_runs.h"

typedef struct {
  bool first;
  int ar_min;
  int ar_max;
  long nfill;
} Ar_stats_t;

bool Ar(int il_ar,Lut_t *lut, Img_coord_int_t *size_in, int ***line_in, bool mask_flag, 
        char **mask_line, char **ddv_line, int **line_ar, int **line_ar_stats, Ar_stats_t *ar_stats, 
        Ar_gridcell_t *ar_gridcell,sixs_tables_t *sixs_tables, int loaded_ar_results);

int ArInterp(Lut_t *lut, Img_coord_int_t *loc, int ***line_ar, int *inter_aot);
int Fill_Ar_Gaps(Lut_t *lut, int ***line_ar, int ib);

int read_ar_results_from_file(char *filename, Ar_gridcell_t *ar_gridcell, 
                              int ***line_ar, TileDef_t *tile_def, Lut_t *lut);
int write_ar_results_to_file(char *filename, Ar_gridcell_t *ar_gridcell,
                             int ***line_ar);
#endif
