/*
 * @Author: Zhiyuan Cao
 * @Date: 2022-08-22 18:40:57
 * @LastEditors: Zhiyuan Cao
 * @LastEditTime: 2022-08-22 19:04:49
 * @FilePath: /xv6-labs-2021/user/sleep.c
 * @Description:
 *
 * Copyright (c) 2022 by Zhiyuan Cao, All Rights Reserved.
 */

#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    int t;

    // wrong number of arguments
    if (argc <= 1)
    {
        fprintf(2, "wrong number of arguments\n");
        exit(0);
    }

    t = atoi(argv[1]);
    sleep(t);
    exit(0);
}
