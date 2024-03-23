#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "./coder.h"

#define COL_NUMBER 1000000

uint32_t generate_number()
{
    const int r = rand();
    const int p = r % 100;
    if (p < 90)
    {
        return r % 128;
    }
    if (p < 95)
    {
        return r % 16384;
    }
    if (p < 99)
    {
        return r % 2097152;
    }
    return r % 268435455;
}

void writ_num()
{

    FILE *f_unc = fopen("uncompressed.dat", "wb");
    FILE *f_c = fopen("compressed.dat", "wb");

    uint8_t buf;

    if (f_c != NULL && f_unc != NULL)
    {
        for (long int i = 0; i < COL_NUMBER; i++)
        {
            uint32_t num = generate_number();
            size_t variant = encode_varint(num, &buf);

            fwrite(&num, sizeof(num), 1, f_unc);
            fwrite(&buf, variant, 1, f_c);
        }

        fclose(f_c);
        fclose(f_unc);
    }
}

void read_dat()
{
    FILE *f_unc = fopen("uncompressed.dat", "rb");
    FILE *f_c = fopen("compressed.dat", "rb");

    uint8_t *buf_uint8;
    uint32_t *buf_uint32;

    buf_uint32 = malloc(COL_NUMBER * sizeof(uint32_t));
    buf_uint8 = malloc(COL_NUMBER * sizeof(uint8_t));

    fread(buf_uint32, sizeof(uint32_t), COL_NUMBER, f_unc);
    fread(buf_uint8, sizeof(uint8_t), COL_NUMBER, f_c);

    uint32_t i = 0;
    uint32_t j = 0;

    for (; i <= COL_NUMBER; i++)
    {
        for (; j <= COL_NUMBER; j++)
        {
            if (buf_uint32[i] != buf_uint8[j])
            {
                buf_uint32++;
            }
            if (buf_uint32[i] == buf_uint8[j])
            {
                buf_uint32++;
                buf_uint8++;
            }
        }
    }

    if (i - 1 == COL_NUMBER && j - 1 == COL_NUMBER)
    {
        printf("Файлы одинаковые\n");
    }
    else
    {
        printf("Файлы не одинаковые\n");
    }
    fclose(f_c);
    fclose(f_unc);
}
