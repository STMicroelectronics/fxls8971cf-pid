/**
  ******************************************************************************
  * @file    fxls8971cf_reg.h
  * @author  Sensors Software Solution Team
  * @brief   This file contains all the functions prototypes for the
  *          fxls8971cf_reg.c driver.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef FXLS8971CF_REG_H
#define FXLS8971CF_REG_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stddef.h>

/** @defgroup  Endianness definitions
  * @{
  *
  */

#ifndef DRV_BYTE_ORDER
#ifndef __BYTE_ORDER__

#define DRV_LITTLE_ENDIAN 1234
#define DRV_BIG_ENDIAN    4321

/** if _BYTE_ORDER is not defined, choose the endianness of your architecture
  * by uncommenting the define which fits your platform endianness
  */
//#define DRV_BYTE_ORDER    DRV_BIG_ENDIAN
#define DRV_BYTE_ORDER    DRV_LITTLE_ENDIAN

#else /* defined __BYTE_ORDER__ */

#define DRV_LITTLE_ENDIAN  __ORDER_LITTLE_ENDIAN__
#define DRV_BIG_ENDIAN     __ORDER_BIG_ENDIAN__
#define DRV_BYTE_ORDER     __BYTE_ORDER__

#endif /* __BYTE_ORDER__*/
#endif /* DRV_BYTE_ORDER */

/* Bit Endianess template reference */
/*
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t bit0                         : 1;
  uint8_t bit1                         : 1;
  uint8_t bit2                         : 1;
  uint8_t bit3                         : 1;
  uint8_t bit4                         : 1;
  uint8_t bit5                         : 1;
  uint8_t bit6                         : 1;
  uint8_t bit7                         : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t bit7                         : 1;
  uint8_t bit6                         : 1;
  uint8_t bit5                         : 1;
  uint8_t bit4                         : 1;
  uint8_t bit3                         : 1;
  uint8_t bit2                         : 1;
  uint8_t bit1                         : 1;
  uint8_t bit0                         : 1;
#endif // DRV_BYTE_ORDER
} bitwise_t;
*/

/**
  * @}
  *
  */

/** @addtogroup  Interfaces_Functions
  * @brief       This section provide a set of functions used to read and
  *              write a generic register of the device.
  *              MANDATORY: return 0 -> no Error.
  * @{
  *
  */

typedef int32_t (*stmdev_write_ptr)(void *, uint8_t, const uint8_t *, uint16_t);
typedef int32_t (*stmdev_read_ptr)(void *, uint8_t, uint8_t *, uint16_t);
typedef void (*stmdev_mdelay_ptr)(uint32_t millisec);

/* STdC-style context */
typedef struct
{
  /** Component mandatory fields **/
  stmdev_write_ptr  write_reg;
  stmdev_read_ptr   read_reg;
  /** Component optional fields **/
  stmdev_mdelay_ptr   mdelay;
  /** Customizable optional pointer **/
  void *handle;

  /** private data **/
  void *priv_data;
} stmdev_ctx_t;

/**
  * @}
  *
  */

typedef struct
{
  /* per driver instance private data */
} fxls8971cf_priv_t;

#define FXLS8971_SETB         1  /* Set Bit */
#define FXLS8971_RSTB         0  /* Reset Bit */

/* FXLS8971CF I2C addresses adjusted based as 8-bit addressing */
#define FXLS8971CF_I2C_ADD_SA0_0 (0x18U << 1)
#define FXLS8971CF_I2C_ADD_SA0_1 (0x19U << 1)

/* WHO_AM_I value for FXLS89xxx family.*/
#define FXLS8964_WHO_AM_I_VAL    (0x84) /* Who AM I Value of FXLS8964AF */
#define FXLS8967_WHO_AM_I_VAL    (0x87) /* Who AM I Value of FXLS8967AF */
#define FXLS8968_WHO_AM_I_VAL    (0x88) /* Who AM I Value of FXLS8968CF */
#define FXLS8974_WHO_AM_I_VAL    (0x86) /* Who AM I Value of FXLS8974CF */
#define FXLS8961_WHO_AM_I_VAL    (0x81) /* Who AM I Value of FXLS8961AF */
#define FXLS8971_WHO_AM_I_VAL    (0x83) /* Who AM I Value of FXLS8971CF */

/* FXLS8971CF raw data size. */
#define NUM_AXES                 (0x03)
#define ACCEL_RAW_BYTE           (NUM_AXES * 2)

/* FXLS8971CF FIFO Config */
#define MAX_FIFO_DEPTH           (32)
#define FIFO_DEPTH               (8)

/* FXLS8971CF sensitivity factor. */
#define ACCEL_2G_SENS            (0.000976) /* Sensitivity factor for 2G FS */
#define ACCEL_4G_SENS            (0.001953) /* Sensitivity factor for 4G FS */
#define ACCEL_8G_SENS            (0.003906) /* Sensitivity factor for 8G FS */
#define ACCEL_16G_SENS           (0.007813) /* Sensitivity factor for 16G FS */

/* FXLS8971CF INT Pins */
#define FXLS8971CF_INT1              (0)
#define FXLS8971CF_INT2              (1)
#define FXLS8971CF_INT_NOT_ASSIGNED  (255)

/* The FXLS8971CF Sensor Internal Register Map. */

#define FXLS8971CF_INT_STATUS           0x00
#define FXLS8971CF_TEMP_OUT             0x01
#define FXLS8971CF_VECM_LSB             0x02
#define FXLS8971CF_VECM_MSB             0x03
#define FXLS8971CF_OUT_X_LSB            0x04
#define FXLS8971CF_OUT_X_MSB            0x05
#define FXLS8971CF_OUT_Y_LSB            0x06
#define FXLS8971CF_OUT_Y_MSB            0x07
#define FXLS8971CF_OUT_Z_LSB            0x08
#define FXLS8971CF_OUT_Z_MSB            0x09
#define FXLS8971CF_BUF_STATUS           0x0B
#define FXLS8971CF_BUF_X_LSB            0x0C
#define FXLS8971CF_BUF_X_MSB            0x0D
#define FXLS8971CF_BUF_Y_LSB            0x0E
#define FXLS8971CF_BUF_Y_MSB            0x0F
#define FXLS8971CF_BUF_Z_LSB            0x10
#define FXLS8971CF_BUF_Z_MSB            0x11
#define FXLS8971CF_PROD_REV             0x12
#define FXLS8971CF_WHO_AM_I             0x13
#define FXLS8971CF_SYS_MODE             0x14
#define FXLS8971CF_SENS_CONFIG1         0x15
#define FXLS8971CF_SENS_CONFIG2         0x16
#define FXLS8971CF_SENS_CONFIG3         0x17
#define FXLS8971CF_SENS_CONFIG4         0x18
#define FXLS8971CF_SENS_CONFIG5         0x19
#define FXLS8971CF_WAKE_IDLE_LSB        0x1A
#define FXLS8971CF_WAKE_IDLE_MSB        0x1B
#define FXLS8971CF_SLEEP_IDLE_LSB       0x1C
#define FXLS8971CF_SLEEP_IDLE_MSB       0x1D
#define FXLS8971CF_ASLP_COUNT_LSB       0x1E
#define FXLS8971CF_ASLP_COUNT_MSB       0x1F
#define FXLS8971CF_INT_EN               0x20
#define FXLS8971CF_INT_PIN_SEL          0x21
#define FXLS8971CF_OFF_X                0x22
#define FXLS8971CF_OFF_Y                0x23
#define FXLS8971CF_OFF_Z                0x24
#define FXLS8971CF_BUF_CONFIG1          0x26
#define FXLS8971CF_BUF_CONFIG2          0x27
#define FXLS8971CF_ORIENT_STATUS        0x28
#define FXLS8971CF_ORIENT_CONFIG        0x29
#define FXLS8971CF_ORIENT_DBCOUNT       0x2A
#define FXLS8971CF_ORIENT_BF_ZCOMP      0x2B
#define FXLS8971CF_ORIENT_THS_REG       0x2C
#define FXLS8971CF_SDCD_INT_SRC1        0x2D
#define FXLS8971CF_SDCD_INT_SRC2        0x2E
#define FXLS8971CF_SDCD_CONFIG1         0x2F
#define FXLS8971CF_SDCD_CONFIG2         0x30
#define FXLS8971CF_SDCD_OT_DBCNT        0x31
#define FXLS8971CF_SDCD_WT_DBCNT        0x32
#define FXLS8971CF_SDCD_LTHS_LSB        0x33
#define FXLS8971CF_SDCD_LTHS_MSB        0x34
#define FXLS8971CF_SDCD_UTHS_LSB        0x35
#define FXLS8971CF_SDCD_UTHS_MSB        0x36
#define FXLS8971CF_SELF_TEST_CONFIG1    0x37
#define FXLS8971CF_SELF_TEST_CONFIG2    0x38

/* Bitfield structs – pack exactly 1 byte.*/

/*--------------------------------
** Register: INT_STATUS
** Enum: FXLS8971CF_INT_STATUS
** --
** Offset : 0x00 Interrupt and system status event flags.
** ------------------------------*/
typedef union
{
  struct
  {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
    uint8_t src_boot : 1; /*  System boot complete event flag. */
    uint8_t src_aslp : 1; /*  Auto-Wake/Sleep event status flag. */
    uint8_t src_orient : 1; /*  Orientation change event flag. */
    uint8_t src_sdcd_wt : 1; /*  SDCD within thresholds condition event flag. */
    uint8_t src_sdcd_ot : 1; /*  SDCD outside of threshold condition event flag. */
    uint8_t src_buf : 1; /*  Output data buffer status event flag. */
    uint8_t src_ovf : 1; /*  Output data overflow event flag. */
    uint8_t src_drdy : 1; /*  Output data ready event flag. */
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
    uint8_t src_drdy : 1; /*  Output data ready event flag. */
    uint8_t src_ovf : 1; /*  Output data overflow event flag. */
    uint8_t src_buf : 1; /*  Output data buffer status event flag. */
    uint8_t src_sdcd_ot : 1; /*  SDCD outside of threshold condition event flag. */
    uint8_t src_sdcd_wt : 1; /*  SDCD within thresholds condition event flag. */
    uint8_t src_orient : 1; /*  Orientation change event flag. */
    uint8_t src_aslp : 1; /*  Auto-Wake/Sleep event status flag. */
    uint8_t src_boot : 1; /*  System boot complete event flag. */
#endif /* DRV_BYTE_ORDER */
  } b;
  uint8_t w;
} fxls8971cf_int_status_t;

/*
** SYS_MODE - Bit field value definitions
*/
#define FXLS8971CF_INT_STATUS_SRC_BOOT ((uint8_t)0x01)
#define FXLS8971CF_INT_STATUS_SRC_ASLP ((uint8_t)0x02)
#define FXLS8971CF_INT_STATUS_SRC_ORIENT ((uint8_t)0x04)
#define FXLS8971CF_INT_STATUS_SRC_SDCD_WT ((uint8_t)0x08)
#define FXLS8971CF_INT_STATUS_SRC_SDCD_OT ((uint8_t)0x10)
#define FXLS8971CF_INT_STATUS_SRC_BUF ((uint8_t)0x20)
#define FXLS8971CF_INT_STATUS_SRC_OVF ((uint8_t)0x40)
#define FXLS8971CF_INT_STATUS_SRC_DRDY ((uint8_t)0x80)
/*------------------------------*/

/*--------------------------------
** Register: TEMP_OUT
** Enum: FXLS8971CF_TEMP_OUT
** --
** Offset : 0x01 Temperature output data.
** ------------------------------*/
typedef uint8_t fxls8971cf_temp_out_t;

/*--------------------------------
** Register: VECM_LSB
** Enum: FXLS8971CF_VECM_LSB
** --
** Offset : 0x02 12-bit unsigned vector magnitude LSB.
** ------------------------------*/
typedef uint8_t fxls8971cf_vecm_lsb_t;

/*--------------------------------
** Register: VECM_MSB
** Enum: FXLS8971CF_VECM_MSB
** --
** Offset : 0x03 12-bit unsigned vector magnitude MSB.
** ------------------------------*/
typedef uint8_t fxls8971cf_vecm_msb_t;

/*--------------------------------
** Register: OUT_X_LSB
** Enum: FXLS8971CF_OUT_X_LSB
** --
** Offset : 0x04 LSB of current 12-bit X-axis accelerometer output data.
** ------------------------------*/
typedef uint8_t fxls8971cf_out_x_lsb_t;

/*--------------------------------
** Register: OUT_X_MSB
** Enum: FXLS8971CF_OUT_X_MSB
** --
** Offset : 0x05 MSB of current 12-bit X-axis accelerometer output data.
** ------------------------------*/
typedef uint8_t fxls8971cf_out_x_msb_t;

/*--------------------------------
** Register: OUT_Y_LSB
** Enum: FXLS8971CF_OUT_Y_LSB
** --
** Offset : 0x06 LSB of current 12-bit Y-axis accelerometer output data.
** ------------------------------*/
typedef uint8_t fxls8971cf_out_y_lsb_t;

/*--------------------------------
** Register: OUT_Y_MSB
** Enum: FXLS8971CF_OUT_Y_MSB
** --
** Offset : 0x07 MSB of current 12-bit Y-axis accelerometer output data.
** ------------------------------*/
typedef uint8_t fxls8971cf_out_x_msb_t;

/*--------------------------------
** Register: OUT_Z_LSB
** Enum: FXLS8971CF_OUT_Z_LSB
** --
** Offset : 0x08 LSB of current 12-bit Z-axis accelerometer output data.
** ------------------------------*/
typedef uint8_t fxls8971cf_out_z_lsb_t;

/*--------------------------------
** Register: OUT_Z_MSB
** Enum: FXLS8971CF_OUT_Z_MSB
** --
** Offset : 0x09 MSB of current 12-bit Z-axis accelerometer output data.
** ------------------------------*/
typedef uint8_t fxls8971cf_out_z_msb_t;

/*--------------------------------
** Register: BUF_STATUS
** Enum: FXLS8971CF_BUF_STATUS
** --
** Offset : 0x0B Buf status.
** ------------------------------*/
typedef union
{
  struct
  {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
    uint8_t buf_cnt : 6; /*  Count of the acceleration data samples */
    uint8_t buf_ovf : 1; /*  Buffer Overflow Event Flag */
    uint8_t buf_wmrk : 1; /*  Buffer Watermark Event Flag */
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
    uint8_t buf_wmrk : 1; /*  Buffer Watermark Event Flag */
    uint8_t buf_ovf : 1; /*  Buffer Overflow Event Flag */
    uint8_t buf_cnt : 6; /*  Count of the acceleration data samples */
#endif /* DRV_BYTE_ORDER */
  } b;
  uint8_t w;
} fxls8971cf_buf_status_t;

/*
** SYS_MODE - Bit field value definitions
*/
#define FXLS8971CF_BUF_STATUS_BUF_OVF    ((uint8_t) 0x40)
#define FXLS8971CF_BUF_STATUS_BUF_WMRK   ((uint8_t) 0x80)
/*--------------------------------
** Register: BUF_X_LSB
** Enum: FXLS8971CF_BUF_X_LSB
** --
** Offset : 0x0C LSB Head Tail output buffer buffer X axis.
** ------------------------------*/
typedef uint8_t fxls8971cf_buf_x_lsb_t;


/*--------------------------------
** Register: BUF_X_MSB
** Enum: FXLS8971CF_BUF_X_MSB
** --
** Offset : 0x0D MSB Head Tail output buffer buffer Z axis.
** ------------------------------*/
typedef uint8_t fxls8971cf_buf_x_msb_t;


/*--------------------------------
** Register: BUF_Y_LSB
** Enum: FXLS8971CF_BUF_Y_LSB
** --
** Offset : 0x0E LSB Head Tail output buffer buffer Y axis.
** ------------------------------*/
typedef uint8_t fxls8971cf_buf_y_lsb_t;


/*--------------------------------
** Register: BUF_Y_MSB
** Enum: FXLS8971CF_BUF_Y_MSB
** --
** Offset : 0x0F MSB Head Tail output buffer buffer Y axis.
** ------------------------------*/
typedef uint8_t fxls8971cf_buf_y_msb_t;


/*--------------------------------
** Register: BUF_Z_LSB
** Enum: FXLS8971CF_BUF_Z_LSB
** --
** Offset : 0x10 LSB Head Tail output buffer buffer Z axis.
** ------------------------------*/
typedef uint8_t fxls8971cf_buf_z_lsb_t;


/*--------------------------------
** Register: BUF_Z_MSB
** Enum: FXLS8971CF_BUF_Z_MSB
** --
** Offset : 0x11 MSB Head Tail output buffer buffer Z axis.
** ------------------------------*/
typedef uint8_t fxls8971cf_buf_z_msb_t;

/*--------------------------------
** Register: PROD_REV
** Enum: FXLS8971CF_PROD_REV
** --
** Offset : 0x12 Product revision number in BCD format.
** ------------------------------*/
typedef union
{
  struct
  {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
    uint8_t prod_rev_min : 4; /* Minor product revision info */
    uint8_t prod_rev_maj : 4; /* Major product revision info */
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
    uint8_t prod_rev_maj : 4; /* Major product revision info */
    uint8_t prod_rev_min : 4; /* Minor product revision info */
#endif /* DRV_BYTE_ORDER */
  } b;
  uint8_t w;
} fxls8971cf_prod_rev_t;

/*--------------------------------
** Register: WHO_AM_I
** Enum: FXLS8971CF_WHO_AM_I
** --
** Offset : 0x13 8-bit NXP unique sensor Product ID.
** ------------------------------*/
typedef uint8_t fxls8971cf_who_am_i_t;

/*--------------------------------
** Register: SYS_MODE
** Enum: FXLS8971CF_SYS_MODE
** --
** Offset : 0x14 Current System Operating Mode.
** ------------------------------*/
typedef union
{
  struct
  {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
    uint8_t sys_mode : 2; /* System operating mode. */
    uint8_t buf_gate_cnt : 5; /* ODR cnt since the BUF_GATE_ERR flag asserted. */
    uint8_t buf_gate_error : 1; /* Buffer gate error flag. */
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
    uint8_t buf_gate_error : 1; /* Buffer gate error flag. */
    uint8_t buf_gate_cnt : 5; /* ODR cnt since the BUF_GATE_ERR flag asserted. */
    uint8_t sys_mode : 2; /* System operating mode. */
#endif /* DRV_BYTE_ORDER */
  } b;
  uint8_t w;
} fxls8971cf_sys_mode_t;

/*
** SYS_MODE - Bit field value definitions
*/
#define FXLS8971CF_SYS_MODE_BUF_GATE_ERROR_NO ((uint8_t)0x00) /* Not Detected. */
#define FXLS8971CF_SYS_MODE_BUF_GATE_ERROR_YES ((uint8_t)0x80)/* Detected. */
#define FXLS8971CF_SYS_MODE_SYS_MODE_STANDBY ((uint8_t)0x00)  /* Standby Mode. */
#define FXLS8971CF_SYS_MODE_SYS_MODE_WAKE ((uint8_t)0x01)     /* Wake Mode. */
#define FXLS8971CF_SYS_MODE_SYS_MODE_SLEEP ((uint8_t)0x02)    /* Sleep Mode. */
#define FXLS8971CF_SYS_MODE_SYS_MODE_EXT_TRIG ((uint8_t)0x03) /* External Trig Mode. */
/*------------------------------*/

/*--------------------------------
** Register: SENS_CONFIG1
** Enum: FXLS8971CF_SENS_CONFIG1
** --
** Offset : 0x15 Configuration register 1.
** ------------------------------*/
typedef union
{
  struct
  {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
    uint8_t active : 1; /* Standby/Active mode selection */
    uint8_t fsr : 2; /* Full-scale measurement range (FSR) selection. */
    uint8_t spi_m : 1; /* SPI interface mode selection */
    uint8_t st_pol : 1; /* Self-Test Displacement Polarity */
    uint8_t st_axis_sel : 2; /*  Self-Test Axis Selection */
    uint8_t rst : 1; /* The RST bit may be used to initiate a software reset. */
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
    uint8_t rst : 1; /* The RST bit may be used to initiate a software reset. */
    uint8_t st_axis_sel : 2; /*  Self-Test Axis Selection */
    uint8_t st_pol : 1; /* Self-Test Displacement Polarity */
    uint8_t spi_m : 1; /* SPI interface mode selection */
    uint8_t fsr : 2; /* Full-scale measurement range (FSR) selection. */
    uint8_t active : 1; /* Standby/Active mode selection */
#endif /* DRV_BYTE_ORDER */
  } b;
  uint8_t w;
} fxls8971cf_sens_config1_t;

/*
** SENS_CONFIG1 - Bit field value definitions
*/
#define FXLS8971CF_SENS_CONFIG1_RST_RST ((uint8_t)0x80) /* Trigger Reset */
#define FXLS8971CF_SENS_CONFIG1_ST_AXIS_SEL_DISABLED ((uint8_t)0x00) /* Self-Test function disabled */
#define FXLS8971CF_SENS_CONFIG1_ST_AXIS_SEL_EN_X ((uint8_t)0x20) /* Self-Test enabled for X-axis */
#define FXLS8971CF_SENS_CONFIG1_ST_AXIS_SEL_EN_Y ((uint8_t)0x40) /* Self-Test enabled for Y-axis */
#define FXLS8971CF_SENS_CONFIG1_ST_AXIS_SEL_EN_Z ((uint8_t)0x60) /* Self-Test enabled for Z-axis */
#define FXLS8971CF_SENS_CONFIG1_ST_POL_POSITIVE ((uint8_t)0x00) /* Displacement in the positive direction */
#define FXLS8971CF_SENS_CONFIG1_ST_POL_NEGATIVE ((uint8_t)0x10) /* Displacement in the negative direction */
#define FXLS8971CF_SENS_CONFIG1_SPI_M_FOUR ((uint8_t)0x00) /* 4-wire interface mode is selected. */
#define FXLS8971CF_SENS_CONFIG1_SPI_M_THREE ((uint8_t)0x08) /* 3-wire interface mode is selected. */
#define FXLS8971CF_SENS_CONFIG1_FSR_2G ((uint8_t)0x00) /* ±2g; 0.98 mg/LSB (1024 LSB/g) nominal */
#define FXLS8971CF_SENS_CONFIG1_FSR_4G ((uint8_t)0x02) /* ±4g; 1.95 mg/LSB (512 LSB/g) nominal */
#define FXLS8971CF_SENS_CONFIG1_FSR_8G ((uint8_t)0x04) /* ±8g; 3.91 mg/LSB (256 LSB/g) nominal */
#define FXLS8971CF_SENS_CONFIG1_FSR_16G ((uint8_t)0x06) /* ±16g; 7.81 mg/LSB (128 LSB/g) nominal */
#define FXLS8971CF_SENS_CONFIG1_ACTIVE_STANDBY ((uint8_t)0x00) /*  Standby mode. */
#define FXLS8971CF_SENS_CONFIG1_ACTIVE_ACTIVE ((uint8_t)0x01) /*  Active mode. */
/*------------------------------*/

/*--------------------------------
** Register: SENS_CONFIG2
** Enum: FXLS8971CF_SENS_CONFIG2
** --
** Offset : 0x16 Configuration register 2.
** ------------------------------*/
typedef union
{
  struct
  {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
    uint8_t f_read : 1; /* Fast-read mode selection. */
    uint8_t anic_temp : 1; /* Temperature output data auto-increment control. */
    uint8_t _reserved_ : 1;
    uint8_t le_be : 1; /* Little/Big-endian output mode selection. */
    uint8_t sleep_pm : 2; /* SLEEP power mode selection. */
    uint8_t wake_pm : 2; /* WAKE power mode selection. */
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
    uint8_t wake_pm : 2; /* WAKE power mode selection. */
    uint8_t sleep_pm : 2; /* SLEEP power mode selection. */
    uint8_t le_be : 1; /* Little/Big-endian output mode selection. */
    uint8_t _reserved_ : 1;
    uint8_t anic_temp : 1; /* Temperature output data auto-increment control. */
    uint8_t f_read : 1; /* Fast-read mode selection. */
#endif /* DRV_BYTE_ORDER */
  } b;
  uint8_t w;
} fxls8971cf_sens_config2_t;

/*
** SENS_CONFIG2 - Bit field value definitions
*/
#define FXLS8971CF_SENS_CONFIG2_WAKE_PM_LOW_POWER ((uint8_t)0x00)  /*  Low Power mode is selected. */
#define FXLS8971CF_SENS_CONFIG2_WAKE_PM_HIGH_PERF ((uint8_t)0x40)  /*  High Performance Mode */
#define FXLS8971CF_SENS_CONFIG2_WAKE_PM_FLEX_PERF ((uint8_t)0x80)  /*  Flexible Performance Mode. */
#define FXLS8971CF_SENS_CONFIG2_SLEEP_PM_LOW_POWER ((uint8_t)0x00) /*  Low Power mode */
#define FXLS8971CF_SENS_CONFIG2_SLEEP_PM_HIGH_PERF ((uint8_t)0x10) /*  High Performance Mode */
#define FXLS8971CF_SENS_CONFIG2_SLEEP_PM_FLEX_PERF ((uint8_t)0x20) /*  Flexible Performance Mode */
#define FXLS8971CF_SENS_CONFIG2_LE_BE_LE ((uint8_t)0x00) /*  Little-endian output mode is selected. */
#define FXLS8971CF_SENS_CONFIG2_LE_BE_BE ((uint8_t)0x08) /*  Big-endian output mode is selected. */
#define FXLS8971CF_SENS_CONFIG2_ANIC_TEMP_DIS ((uint8_t)0x00) /* TEMP_OUT not in auto-increment */
#define FXLS8971CF_SENS_CONFIG2_ANIC_TEMP_EN ((uint8_t)0x02) /* TEMP_OUT in auto-increment */
#define FXLS8971CF_SENS_CONFIG2_F_READ_NORMAL ((uint8_t)0x00) /* Normal read mode. */
#define FXLS8971CF_SENS_CONFIG2_F_READ_FAST ((uint8_t)0x01) /* Fast read mode. */
/*------------------------------*/

/*--------------------------------
** Register: SENS_CONFIG3
** Enum: FXLS8971CF_SENS_CONFIG3
** --
** Offset : 0x17 Configuration register 3.
** ------------------------------*/
typedef union
{
  struct
  {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
    uint8_t sleep_odr : 4; /* Sleep ODR */
    uint8_t wake_odr : 4; /* Wake ODR */
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
    uint8_t wake_odr : 4; /* Wake ODR */
    uint8_t sleep_odr : 4; /* Sleep ODR */
#endif /* DRV_BYTE_ORDER */
  } b;
  uint8_t w;
} fxls8971cf_sens_config3_t;

/*
** SENS_CONFIG3 - Bit field value definitions
*/
#define FXLS8971CF_SENS_CONFIG3_WAKE_ODR_3200HZ ((uint8_t)0x00)
#define FXLS8971CF_SENS_CONFIG3_WAKE_ODR_1600HZ ((uint8_t)0x10)
#define FXLS8971CF_SENS_CONFIG3_WAKE_ODR_800HZ ((uint8_t)0x20)
#define FXLS8971CF_SENS_CONFIG3_WAKE_ODR_400HZ ((uint8_t)0x30)
#define FXLS8971CF_SENS_CONFIG3_WAKE_ODR_200HZ ((uint8_t)0x40)
#define FXLS8971CF_SENS_CONFIG3_WAKE_ODR_100HZ ((uint8_t)0x50)
#define FXLS8971CF_SENS_CONFIG3_WAKE_ODR_50HZ ((uint8_t)0x60)
#define FXLS8971CF_SENS_CONFIG3_WAKE_ODR_25HZ ((uint8_t)0x70)
#define FXLS8971CF_SENS_CONFIG3_WAKE_ODR_12_5HZ ((uint8_t)0x80)
#define FXLS8971CF_SENS_CONFIG3_WAKE_ODR_6_25HZ ((uint8_t)0x90)
#define FXLS8971CF_SENS_CONFIG3_WAKE_ODR_3_125HZ ((uint8_t)0xa0)
#define FXLS8971CF_SENS_CONFIG3_WAKE_ODR_1_563HZ ((uint8_t)0xb0)
#define FXLS8971CF_SENS_CONFIG3_WAKE_ODR_0_781HZ ((uint8_t)0xc0)
#define FXLS8971CF_SENS_CONFIG3_SLEEP_ODR_3200HZ ((uint8_t)0x00)
#define FXLS8971CF_SENS_CONFIG3_SLEEP_ODR_1600HZ ((uint8_t)0x01)
#define FXLS8971CF_SENS_CONFIG3_SLEEP_ODR_800HZ ((uint8_t)0x02)
#define FXLS8971CF_SENS_CONFIG3_SLEEP_ODR_400HZ ((uint8_t)0x03)
#define FXLS8971CF_SENS_CONFIG3_SLEEP_ODR_200HZ ((uint8_t)0x04)
#define FXLS8971CF_SENS_CONFIG3_SLEEP_ODR_100HZ ((uint8_t)0x05)
#define FXLS8971CF_SENS_CONFIG3_SLEEP_ODR_50HZ ((uint8_t)0x06)
#define FXLS8971CF_SENS_CONFIG3_SLEEP_ODR_25HZ ((uint8_t)0x07)
#define FXLS8971CF_SENS_CONFIG3_SLEEP_ODR_12_5HZ ((uint8_t)0x08)
#define FXLS8971CF_SENS_CONFIG3_SLEEP_ODR_6_25HZ ((uint8_t)0x09)
#define FXLS8971CF_SENS_CONFIG3_SLEEP_ODR_3_125HZ ((uint8_t)0x0a)
#define FXLS8971CF_SENS_CONFIG3_SLEEP_ODR_1_563HZ ((uint8_t)0x0b)
#define FXLS8971CF_SENS_CONFIG3_SLEEP_ODR_0_781HZ ((uint8_t)0x0c)
/*------------------------------*/

/*--------------------------------
** Register: SENS_CONFIG4
** Enum: FXLS8971CF_SENS_CONFIG4
** --
** Offset : 0x18 Configuration register 4.
** ------------------------------*/
typedef union
{
  struct
  {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
    uint8_t int_pol : 1; /* Interrupt logic polarity on INT1 and INT2 pins. */
    uint8_t int_pp_od : 1; /* INT1 and INT2 pins output driver selection. */
    uint8_t int2_func : 1; /* INT2 output / EXT_TRIG input pin selection. */
    uint8_t drdy_pul : 1; /* Pulse generation option for DRDY event. */
    uint8_t wk_orient : 1; /* Orientation change event Auto-WAKE/SLEEP enable. */
    uint8_t wk_sdcd_ot : 1; /* SDCD outside of thresholds event Auto-WAKE/SLEEP enable. */
    uint8_t wk_sdcd_wt : 1; /* SDCD within thresholds event Auto-WAKE/SLEEP enable. */
    uint8_t ext_trig_m : 1; /* External trigger function acquisition mode. */
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
    uint8_t ext_trig_m : 1; /* External trigger function acquisition mode. */
    uint8_t wk_sdcd_wt : 1; /* SDCD within thresholds event Auto-WAKE/SLEEP enable. */
    uint8_t wk_sdcd_ot : 1; /* SDCD outside of thresholds event Auto-WAKE/SLEEP enable. */
    uint8_t wk_orient : 1; /* Orientation change event Auto-WAKE/SLEEP enable. */
    uint8_t drdy_pul : 1; /* Pulse generation option for DRDY event. */
    uint8_t int2_func : 1; /* INT2 output / EXT_TRIG input pin selection. */
    uint8_t int_pp_od : 1; /* INT1 and INT2 pins output driver selection. */
    uint8_t int_pol : 1; /* Interrupt logic polarity on INT1 and INT2 pins. */
#endif /* DRV_BYTE_ORDER */
  } b;
  uint8_t w;
} fxls8971cf_sens_config4_t;

/*
** SENS_CONFIG4 - Bit field value definitions
*/
/* Single ADC acquisition on positive edge */
#define FXLS8971CF_SENS_CONFIG4_EXT_TRIG_M_SINGLE ((uint8_t)0x00)
/* Multiple ADC acquisition on positive edge */
#define FXLS8971CF_SENS_CONFIG4_EXT_TRIG_M_MULTIPLE ((uint8_t)0x80)
/* SDCD within thresholds wake event disabled*/
#define FXLS8971CF_SENS_CONFIG4_WK_SDCD_WT_DIS ((uint8_t)0x00)
/* SDCD within thresholds wake event enabled */
#define FXLS8971CF_SENS_CONFIG4_WK_SDCD_WT_EN ((uint8_t)0x40)
/* SDCD outside thresholds wake event disabled */
#define FXLS8971CF_SENS_CONFIG4_WK_SDCD_OT_DIS ((uint8_t)0x00)
/* SDCD outside thresholds wake event enabled */
#define FXLS8971CF_SENS_CONFIG4_WK_SDCD_OT_EN ((uint8_t)0x20)
/* Orientation change wake event disabled */
#define FXLS8971CF_SENS_CONFIG4_WK_ORIENT_DIS ((uint8_t)0x00)
/* Orientation change wake event disabled */
#define FXLS8971CF_SENS_CONFIG4_WK_ORIENT_EN ((uint8_t)0x10)
/* A SRC_DRDY event is output on the INTx pin as an active high or active low signal */
#define FXLS8971CF_SENS_CONFIG4_DRDY_PUL_DIS ((uint8_t)0x00)
/* A 32 μs (nominal) duration pulse is output on the INTx pin once per ODR cycle */
#define FXLS8971CF_SENS_CONFIG4_DRDY_PUL_EN ((uint8_t)0x08)
/* INT2/EXT_TRIG pin is configured for the INT2 Fn */
#define FXLS8971CF_SENS_CONFIG4_INT2_FUNC_INT2 ((uint8_t)0x00)
/* INT2/EXT_TRIG pin is configured as the EXT_TRIG */
#define FXLS8971CF_SENS_CONFIG4_INT2_FUNC_EXT_TRIG ((uint8_t)0x04)
/* INTx output pin is push-pull type. */
#define FXLS8971CF_SENS_CONFIG4_INT_PP_OD_PUSH_PULL ((uint8_t)0x00)
/*  INTx output pin is open-drain/open-source type. */
#define FXLS8971CF_SENS_CONFIG4_INT_PP_OD_OPEN_DRAIN ((uint8_t)0x02)
/* Active low:Interrupt events are signaled with a logical 0 level. */
#define FXLS8971CF_SENS_CONFIG4_INT_POL_ACT_LOW ((uint8_t)0x00)
/*  Active high: interrupt events are signaled with a logical 1 level*/
#define FXLS8971CF_SENS_CONFIG4_INT_POL_ACT_HIGH ((uint8_t)0x01)
/*------------------------------*/

/*--------------------------------
** Register: SENS_CONFIG5
** Enum: FXLS8971CF_SENS_CONFIG5
** --
** Offset : 0x19 Configuration register 5.
** ------------------------------*/
typedef union
{
  struct
  {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
    uint8_t hibernate_en : 1; /* Hibernate mode enable. */
    uint8_t z_dis : 1; /* Z-axis auto-increment disable. */
    uint8_t y_dis : 1; /* Y-axis auto-increment disable. */
    uint8_t x_dis : 1; /* X-axis auto-increment disable. */
    uint8_t vecm_en : 1; /* Vector Magnitude calculation enable. */
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
    uint8_t vecm_en : 1; /* Vector Magnitude calculation enable. */
    uint8_t x_dis : 1; /* X-axis auto-increment disable. */
    uint8_t y_dis : 1; /* Y-axis auto-increment disable. */
    uint8_t z_dis : 1; /* Z-axis auto-increment disable. */
    uint8_t hibernate_en : 1; /* Hibernate mode enable. */
#endif /* DRV_BYTE_ORDER */
  } b;
  uint8_t w;
} fxls8971cf_sens_config5_t;

/*
** SENS_CONFIG5 - Bit field value definitions
*/
/* Vector magnitude function disabled */
#define FXLS8971CF_SENS_CONFIG5_VECM_EN_DIS ((uint8_t)0x00)
/* Vector magnitude function enabled */
#define FXLS8971CF_SENS_CONFIG5_VECM_EN_EN ((uint8_t)0x10)
/* X-axis measurement included in auto-increment */
#define FXLS8971CF_SENS_CONFIG5_X_DIS_EN ((uint8_t)0x00)
/* X-axis measurement excluded from auto-increment */
#define FXLS8971CF_SENS_CONFIG5_X_DIS_DIS ((uint8_t)0x08)
/* Y-axis measurement included in auto-increment */
#define FXLS8971CF_SENS_CONFIG5_Y_DIS_EN ((uint8_t)0x00)
/* Y-axis measurement excluded from auto-increment */
#define FXLS8971CF_SENS_CONFIG5_Y_DIS_DIS ((uint8_t)0x04)
/* Z-axis measurement included in auto-increment */
#define FXLS8971CF_SENS_CONFIG5_Z_DIS_EN ((uint8_t)0x00)
/* Z-axis measurement excluded from auto-increment */
#define FXLS8971CF_SENS_CONFIG5_Z_DIS_DIS ((uint8_t)0x02)
/* Hibernate mode not enabled */
#define FXLS8971CF_SENS_CONFIG5_HIBERNATE_EN_DIS ((uint8_t)0x00)
/* Enable Hibernate mode */
#define FXLS8971CF_SENS_CONFIG5_HIBERNATE_EN_EN ((uint8_t)0x01)
/*------------------------------*/

/*--------------------------------
** Register: WAKE_IDLE_LSB
** Enum: FXLS8971CF_WAKE_IDLE_LSB
** --
** Offset : 0x1A LSB of 12-bit user programmable wake mode idle.
** ------------------------------*/
typedef uint8_t fxls8971cf_wake_idle_lsb_t;

/*--------------------------------
** Register: wake_idle_MSB
** Enum: FXLS8971CF_WAKE_IDLE_MSB
** --
** Offset : 0x1B MSB of 12-bit user programmable wake mode idle.
** ------------------------------*/
typedef uint8_t fxls8971cf_wake_idle_msb_t;

/*--------------------------------
** Register: SLEEP_IDLE_LSB
** Enum: FXLS8971CF_SLEEP_IDLE_LSB
** --
** Offset : 0x1C LSB of 12-bit user programmable sleep mode idle.
** ------------------------------*/
typedef uint8_t fxls8971cf_sleep_idle_lsb_t;

/*--------------------------------
** Register: SLEEP_IDLE_MSB
** Enum: FXLS8971CF_SLEEP_IDLE_MSB
** --
** Offset : 0x1D MSB of 12-bit user programmable sleep mode idle.
** ------------------------------*/
typedef uint8_t fxls8971cf_sleep_idle_msb_t;

/*--------------------------------
** Register: ASLP_COUNT_LSB
** Enum: FXLS8971CF_ASLP_COUNT_LSB
** --
** Offset : 0x1E LSB of ASLP time-out count value used for transitioning into Auto-SLEEP mode.
** ------------------------------*/
typedef uint8_t fxls8971cf_aslp_count_lsb_t;

/*--------------------------------
** Register: ASLP_COUNT_MSB
** Enum: FXLS8971CF_ASLP_COUNT_MSB
** --
** Offset : 0x1F MSB of ASLP time-out count value used for transitioning into Auto-SLEEP mode.
** ------------------------------*/
typedef uint8_t fxls8971cf_aslp_count_msb_t;

/*--------------------------------
** Register: INT_EN
** Enum: FXLS8971CF_INT_EN
** --
** Offset : 0x20 Interrupt output enable register.
** ------------------------------*/
typedef union
{
  struct
  {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
    uint8_t wake_out_en : 1; /* WAKE power state output enable. */
    uint8_t boot_dis : 1; /* Boot interrupt output disable. */
    uint8_t aslp_en : 1; /* Auto-WAKE/SLEEP interrupt output enable. */
    uint8_t orient_en : 1; /* Orientation interrupt output enable. */
    uint8_t sdcd_wt_en : 1; /* SDCD within thresholds interrupt output enable. */
    uint8_t sdcd_ot_en : 1; /* SDCD outside of thresholds interrupt output enable. */
    uint8_t buf_en : 1; /* Output data buffer interrupt output enable */
    uint8_t drdy_en : 1; /* Data Ready interrupt output enable. */
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
    uint8_t drdy_en : 1; /* Data Ready interrupt output enable. */
    uint8_t buf_en : 1; /* Output data buffer interrupt output enable */
    uint8_t sdcd_ot_en : 1; /* SDCD outside of thresholds interrupt output enable. */
    uint8_t sdcd_wt_en : 1; /* SDCD within thresholds interrupt output enable. */
    uint8_t orient_en : 1; /* Orientation interrupt output enable. */
    uint8_t aslp_en : 1; /* Auto-WAKE/SLEEP interrupt output enable. */
    uint8_t boot_dis : 1; /* Boot interrupt output disable. */
    uint8_t wake_out_en : 1; /* WAKE power state output enable. */
#endif /* DRV_BYTE_ORDER */
  } b;
  uint8_t w;
} fxls8971cf_int_en_t;

/*
** INT_EN - Bit field value definitions
*/
#define FXLS8971CF_INT_EN_DRDY_EN_DIS ((uint8_t)0x00) /* DRDY Interrupt is disabled. */
#define FXLS8971CF_INT_EN_DRDY_EN_EN ((uint8_t)0x80) /* DRDY Interrupt enabled. */
#define FXLS8971CF_INT_EN_BUF_EN_DIS ((uint8_t)0x00) /* BUF Interrupt is disabled */
#define FXLS8971CF_INT_EN_BUF_EN_EN ((uint8_t)0x40) /* BUF Interrupt is enabled */
#define FXLS8971CF_INT_EN_SDCD_OT_EN_DIS ((uint8_t)0x00) /* SDCD OT Interrupt is disabled */
#define FXLS8971CF_INT_EN_SDCD_OT_EN_EN ((uint8_t)0x20) /* SDCD OT Interrupt is enabled */
#define FXLS8971CF_INT_EN_SDCD_WT_EN_DIS ((uint8_t)0x00) /* SDCD WT Interrupt is disabled */
#define FXLS8971CF_INT_EN_SDCD_WT_EN_EN ((uint8_t)0x10) /* SDCD WT Interrupt is enabled */
#define FXLS8971CF_INT_EN_ORIENT_EN_DIS ((uint8_t)0x00) /* Orient Interrupt is disabled. */
#define FXLS8971CF_INT_EN_ORIENT_EN_EN ((uint8_t)0x08) /* Orient Interrupt is enabled */
#define FXLS8971CF_INT_EN_ASLP_EN_DIS ((uint8_t)0x00) /* ASLP Interrupt is disabled. */
#define FXLS8971CF_INT_EN_ASLP_EN_EN ((uint8_t)0x04) /* ASLP Interrupt is enabled */
#define FXLS8971CF_INT_EN_BOOT_DIS_EN ((uint8_t)0x00) /* Boot Interrupt is enabled */
#define FXLS8971CF_INT_EN_BOOT_DIS_DIS ((uint8_t)0x02) /* Boot Interrupt is disabled */
#define FXLS8971CF_INT_EN_WAKE_OUT_EN_DIS ((uint8_t)0x00) /* Wake Out Interrupt is disabled */
#define FXLS8971CF_INT_EN_WAKE_OUT_EN_EN ((uint8_t)0x01) /* Wake Out Interrupt is enabled */
/*------------------------------*/

/*--------------------------------
** Register: INT_PIN_SEL
** Enum: FXLS8971CF_INT_PIN_SEL
** --
** Offset : 0x21 Interrupt output pin routing register, INT1 or INT2.
** ------------------------------*/
typedef union
{
  struct
  {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
    uint8_t wk_out_int2 : 1; /* WAKE power state interrupt routing. */
    uint8_t boot_int2 : 1; /* BOOT event interrupt routing. */
    uint8_t aslp_int2 : 1; /* Auto-WAKE/SLEEP event interrupt routing. */
    uint8_t orient_int2 : 1; /* ORIENT event interrupt routing. */
    uint8_t sdcd_wt_int2 : 1; /* SDCD within thresholds event interrupt routing. */
    uint8_t sdcd_ot_int2 : 1; /* SDCD outside of thresholds event interrupt routing. */
    uint8_t buf_int2 : 1; /* Output buffer interrupt routing. */
    uint8_t drdy_int2 : 1; /* Data Ready interrupt routing. */
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
    uint8_t drdy_int2 : 1; /* Data Ready interrupt routing. */
    uint8_t buf_int2 : 1; /* Output buffer interrupt routing. */
    uint8_t sdcd_ot_int2 : 1; /* SDCD outside of thresholds event interrupt routing. */
    uint8_t sdcd_wt_int2 : 1; /* SDCD within thresholds event interrupt routing. */
    uint8_t orient_int2 : 1; /* ORIENT event interrupt routing. */
    uint8_t aslp_int2 : 1; /* Auto-WAKE/SLEEP event interrupt routing. */
    uint8_t boot_int2 : 1; /* BOOT event interrupt routing. */
    uint8_t wk_out_int2 : 1; /* WAKE power state interrupt routing. */
#endif /* DRV_BYTE_ORDER */
  } b;
  uint8_t w;
} fxls8971cf_int_pin_sel_t;

/*
** INT_PIN_SEL - Bit field value definitions
*/
#define FXLS8971CF_INT_PIN_SEL_DRDY_INT2_DIS ((uint8_t)0x00)    /* Interrupt signal routed to INT1 */
#define FXLS8971CF_INT_PIN_SEL_DRDY_INT2_EN ((uint8_t)0x80)     /* Interrupt signal routed to INT2 */
#define FXLS8971CF_INT_PIN_SEL_BUF_INT2_DIS ((uint8_t)0x00)     /* Interrupt signal routed to INT1 */
#define FXLS8971CF_INT_PIN_SEL_BUF_INT2_EN ((uint8_t)0x40)      /* Interrupt signal routed to INT2 */
#define FXLS8971CF_INT_PIN_SEL_SDCD_OT_INT2_DIS ((uint8_t)0x00) /* Interrupt signal routed to INT1 */
#define FXLS8971CF_INT_PIN_SEL_SDCD_OT_INT2_EN ((uint8_t)0x20)  /* Interrupt signal routed to INT2 */
#define FXLS8971CF_INT_PIN_SEL_SDCD_WT_INT2_DIS ((uint8_t)0x00) /* Interrupt signal routed to INT1 */
#define FXLS8971CF_INT_PIN_SEL_SDCD_WT_INT2_EN ((uint8_t)0x10)  /* Interrupt signal routed to INT2 */
#define FXLS8971CF_INT_PIN_SEL_ORIENT_INT2_DIS ((uint8_t)0x00)  /* Interrupt signal routed to INT1 */
#define FXLS8971CF_INT_PIN_SEL_ORIENT_INT2_EN ((uint8_t)0x08)   /* Interrupt signal routed to INT2 */
#define FXLS8971CF_INT_PIN_SEL_ASLP_INT2_DIS ((uint8_t)0x00)    /* Interrupt signal routed to INT1 */
#define FXLS8971CF_INT_PIN_SEL_ASLP_INT2_EN ((uint8_t)0x04)     /* Interrupt signal routed to INT2 */
#define FXLS8971CF_INT_PIN_SEL_BOOT_INT2_DIS ((uint8_t)0x00)    /* Interrupt signal routed to INT1 */
#define FXLS8971CF_INT_PIN_SEL_BOOT_INT2_EN ((uint8_t)0x02)     /* Interrupt signal routed to INT2 */
#define FXLS8971CF_INT_PIN_SEL_WK_OUT_INT2_DIS ((uint8_t)0x00)  /* Interrupt signal routed to INT1 */
#define FXLS8971CF_INT_PIN_SEL_WK_OUT_INT2_EN ((uint8_t)0x01)   /* Interrupt signal routed to INT2 */
/*------------------------------*/

/*--------------------------------
** Register: OFF_X
** Enum: FXLS8971CF_OFF_X
** --
** Offset : 0x22 X-Acceleration zero-g offset.
** ------------------------------*/
typedef uint8_t fxls8971cf_off_x_t;

/*--------------------------------
** Register: OFF_Y
** Enum: FXLS8971CF_OFF_Y
** --
** Offset : 0x23 Y-Acceleration zero-g offset.
** ------------------------------*/
typedef uint8_t fxls8971cf_off_y_t;

/*--------------------------------
** Register: OFF_Z
** Enum: FXLS8971CF_OFF_Z
** --
** Offset : 0x24 Z-Acceleration zero-g offset.
** ------------------------------*/
typedef uint8_t fxls8971cf_off_z_t;



/*--------------------------------
** Register: BUF_CONFIG1
** Enum: FXLS8971CF_BUF_CONFIG1
** --
** Offset : 0x26 Buf configuration1.
** ------------------------------*/
typedef union
{
  struct
  {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
    uint8_t trg_orient : 1; /* Orientation change event trigger enable */
    uint8_t _reserved_  : 1;
    uint8_t trg_sdcd_ot : 1; /* SDCD outside-of-thresholds event buf trigger enable */
    uint8_t trg_sdcd_wt : 1; /* SDCD within-thresholds event buf trigger enable */
    uint8_t buf_gate : 1; /*  Output data buffer gate enable */
    uint8_t buf_mode : 2; /*  Buffer data collection mode */
    uint8_t buf_type : 1; /*  Buffer data read out order */
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
    uint8_t buf_type : 1; /*  Buffer data read out order */
    uint8_t buf_mode : 2; /*  Buffer data collection mode */
    uint8_t buf_gate : 1; /*  Output data buffer gate enable */
    uint8_t trg_sdcd_wt : 1; /*  SDCD within-thresholds event trigger enable */
    uint8_t trg_sdcd_ot : 1; /* SDCD outside-of-thresholds event buffer trigger enable */
    uint8_t _reserved_  : 1;
    uint8_t trg_orient : 1; /* Orientation change event trigger enable */
#endif /* DRV_BYTE_ORDER */
  } b;
  uint8_t w;
} fxls8971cf_buf_config1_t;


/*
** BUF_CONFIG1 - Bit field value definitions
*/
#define FXLS8971CF_BUF_CONFIG1_BUF_TYPE_FIFO         ((uint8_t) 0x00) /* In FIFO mode */
#define FXLS8971CF_BUF_CONFIG1_BUF_TYPE_FILO         ((uint8_t) 0x80) /* First In Last Out (FILO) */
#define FXLS8971CF_BUF_CONFIG1_BUF_MODE_DIS          ((uint8_t) 0x00) /* Buffer is disabled */
#define FXLS8971CF_BUF_CONFIG1_BUF_MODE_STREAM_MODE  ((uint8_t) 0x20) /* Stream Mode */
#define FXLS8971CF_BUF_CONFIG1_BUF_MODE_STOP_MODE    ((uint8_t) 0x40) /* Stop mode */
#define FXLS8971CF_BUF_CONFIG1_BUF_MODE_TRIGGER_MODE ((uint8_t) 0x60) /* Trigger Mode */
#define FXLS8971CF_BUF_CONFIG1_BUF_GATE_BY_PASSED    ((uint8_t) 0x00) /* Buffer gate bypassed */
#define FXLS8971CF_BUF_CONFIG1_BUF_GATE_ENABLED      ((uint8_t) 0x10) /* Buffer gate enabled. */
#define FXLS8971CF_BUF_CONFIG1_TRG_SDCD_WT_DIS       ((uint8_t) 0x00) /* Trigger source disabled. */
#define FXLS8971CF_BUF_CONFIG1_TRG_SDCD_WT_EN        ((uint8_t) 0x08) /* Trigger source enabled. */
#define FXLS8971CF_BUF_CONFIG1_TRG_SDCD_OT_DIS       ((uint8_t) 0x00) /* Trigger source disabled. */
#define FXLS8971CF_BUF_CONFIG1_TRG_SDCD_OT_EN        ((uint8_t) 0x04) /* Trigger source enabled. */
#define FXLS8971CF_BUF_CONFIG1_TRG_ORIENT_DIS        ((uint8_t) 0x00) /* Trigger source disabled. */
#define FXLS8971CF_BUF_CONFIG1_TRG_ORIENT_EN         ((uint8_t) 0x01) /* Trigger source enabled. */
/*------------------------------*/



/*--------------------------------
** Register: BUF_CONFIG2
** Enum: FXLS8971CF_BUF_CONFIG2
** --
** Offset : 0x27 buf configuration2.
** ------------------------------*/
typedef union
{
  struct
  {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
    uint8_t buf_wmrk : 6; /* Buffer sample count watermark */
    uint8_t wake_src_buf : 1; /* Buffer WAKE-to-SLEEP transition source enable */
    uint8_t buf_flush : 1; /* Buffer flush enable */
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
    uint8_t buf_flush : 1; /* Buffer flush enable */
    uint8_t wake_src_buf : 1; /* Buffer WAKE-to-SLEEP transition source enable */
    uint8_t buf_wmrk : 6; /* Buffer sample count watermark */
#endif /* DRV_BYTE_ORDER */
  } b;
  uint8_t w;
} fxls8971cf_buf_config2_t;

/*
** BUF_CONFIG2 - Bit field value definitions
*/
/* Buffer flush operation completed. */
#define FXLS8971CF_BUF_CONFIG2_BUF_FLUSH_COMPLETED  ((uint8_t) 0x00)
/* Buffer flush enable. */
#define FXLS8971CF_BUF_CONFIG2_BUF_FLUSH_EN         ((uint8_t) 0x80)
/* BUF events are ignored */
#define FXLS8971CF_BUF_CONFIG2_WAKE_SRC_BUF_IGNORED ((uint8_t) 0x00)
/* BUF events are enabled */
#define FXLS8971CF_BUF_CONFIG2_WAKE_SRC_BUF_EN      ((uint8_t) 0x40)
/*------------------------------*/

/*--------------------------------
** Register: ORIENT_STATUS
** Enum: FXLS8971CF_ORIENT_STATUS
** --
** Offset : 0x28 Orientation event status.
** ------------------------------*/
typedef union
{
  struct
  {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
    uint8_t bafro : 1; /*  Back or front orientation. */
    uint8_t lapo : 2; /*  Landscape/Portrait orientation. */
    uint8_t _reserved_ : 3;
    uint8_t lo : 1; /*  Z-tilt angle lockout. */
    uint8_t new_orient : 1; /*  Orientation status change flag. */
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
    uint8_t new_orient : 1; /*  Orientation status change flag. */
    uint8_t lo : 1; /*  Z-tilt angle lockout. */
    uint8_t _reserved_ : 3;
    uint8_t lapo : 2; /*  Landscape/Portrait orientation. */
    uint8_t bafro : 1; /*  Back or front orientation. */
#endif /* DRV_BYTE_ORDER */
  } b;
  uint8_t w;
} fxls8971cf_orient_status_t;

/*
** ORIENT_STATUS - Bit field value definitions
*/
#define FXLS8971CF_ORIENT_STATUS_NEW_ORIENT_NO_CHANGE ((uint8_t)0x00) /* No Orient change. */
#define FXLS8971CF_ORIENT_STATUS_NEW_ORIENT_CHANGED ((uint8_t)0x80) /* Orient change detected */
#define FXLS8971CF_ORIENT_STATUS_LO_NOT_DETECTED ((uint8_t)0x00) /* Lockout not detected. */
#define FXLS8971CF_ORIENT_STATUS_LO_DETECTED ((uint8_t)0x40) /* Lockout is detected */
#define FXLS8971CF_ORIENT_STATUS_LAPO_UP ((uint8_t)0x00) /* Portrait up. */
#define FXLS8971CF_ORIENT_STATUS_LAPO_DOWN ((uint8_t)0x02) /* Portrait down. */
#define FXLS8971CF_ORIENT_STATUS_LAPO_RIGHT ((uint8_t)0x04) /* Landscape right. */
#define FXLS8971CF_ORIENT_STATUS_LAPO_LEFT ((uint8_t)0x06) /* Landscape left. */
#define FXLS8971CF_ORIENT_STATUS_BAFRO_FRONT ((uint8_t)0x00) /* Front-facing orientation. */
#define FXLS8971CF_ORIENT_STATUS_BAFRO_BACK ((uint8_t)0x01) /* Back-facing orientation. */
/*------------------------------*/

/*--------------------------------
** Register: ORIENT_CONFIG
** Enum: FXLS8971CF_ORIENT_CONFIG
** --
** Offset : 0x29 Orientation detection function configuration.
** ------------------------------*/
typedef union
{
  struct
  {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
    uint8_t _reserved_ : 6;
    uint8_t orient_enable : 1; /* Orientation detection function enable. */
    uint8_t orient_dbcntm : 1; /* Orientation debounce counter mode selection. */
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
    uint8_t orient_dbcntm : 1; /* Orientation debounce counter mode selection. */
    uint8_t orient_enable : 1; /* Orientation detection function enable. */
    uint8_t _reserved_ : 6;
#endif /* DRV_BYTE_ORDER */
  } b;
  uint8_t w;
} fxls8971cf_orient_config_t;

/*
** ORIENT_CONFIG - Bit field value definitions
*/
/* Orientation debounce counter is decremented whenever the current orientation is different */
#define FXLS8971CF_ORIENT_CONFIG_ORIENT_DBCNTM_DEC ((uint8_t)0x00)
/* Orientation debounce counter is cleared whenever the current orientation is different */
#define FXLS8971CF_ORIENT_CONFIG_ORIENT_DBCNTM_CLR ((uint8_t)0x80)
/* Orientation detection function is disabled. */
#define FXLS8971CF_ORIENT_CONFIG_ORIENT_ENABLE_DIS ((uint8_t)0x00)
/* Orientation detection function is enabled. */
#define FXLS8971CF_ORIENT_CONFIG_ORIENT_ENABLE_EN ((uint8_t)0x40)
/*------------------------------*/

/*--------------------------------
** Register: ORIENT_DBCOUNT
** Enum: FXLS8971CF_ORIENT_DBCOUNT
** --
** Offset : 0x2A Orientation detection debounce counter.
** ------------------------------*/
typedef uint8_t fxls8971cf_orient_dbcount_t;

/*--------------------------------
** Register: ORIENT_BF_ZCOMP
** Enum: FXLS8971CF_ORIENT_BF_ZCOMP
** --
** Offset : 0x2B Orientation back/front and Z-tilt angle compensation register.
** ------------------------------*/
typedef union
{
  struct
  {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
    uint8_t orient_zlock : 3; /* Z-lock out angle threshold. */
    uint8_t _reserved_ : 3;
    uint8_t orient_bkfr : 2; /*  Back-Up / Front-Up trip angle threshold. */
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
    uint8_t orient_bkfr : 2; /*  Back-Up / Front-Up trip angle threshold. */
    uint8_t _reserved_ : 3;
    uint8_t orient_zlock : 3; /* Z-lock out angle threshold. */
#endif /* DRV_BYTE_ORDER */
  } b;
  uint8_t w;
} fxls8971cf_orient_bf_zcomp_t;

/*
** ORIENT_BF_ZCOMP - Bit field value definitions
*/
/* Back to front Z < 80° or Z > 280° and Front to back Z > 100° and Z < 260° */
#define FXLS8971CF_ORIENT_BF_ZCOMP_ORIENT_BKFR_BF_80_280_FB_100_260 ((uint8_t)0x00)
/* Back to front Z < 75° or Z > 285° and Front to back Z > 105° and Z < 255° */
#define FXLS8971CF_ORIENT_BF_ZCOMP_ORIENT_BKFR_BF_75_285_FB_105_255 ((uint8_t)0x40)
/* Back to front Z < 70° or Z > 290° and Front to back Z > 110° and Z < 250° */
#define FXLS8971CF_ORIENT_BF_ZCOMP_ORIENT_BKFR_BF_70_290_FB_110_250 ((uint8_t)0x80)
/* Back to front Z < 65° or Z > 295° and Front to back Z > 115° and Z  < 250° */
#define FXLS8971CF_ORIENT_BF_ZCOMP_ORIENT_BKFR_BF_65_295_FB_115_245 ((uint8_t)0xc0)
/* Resultant angle 13.6 */
#define FXLS8971CF_ORIENT_BF_ZCOMP_ORIENT_ZLOCK_13_6 ((uint8_t)0x00)
/* Resultant angle 17.1 */
#define FXLS8971CF_ORIENT_BF_ZCOMP_ORIENT_ZLOCK_17_1 ((uint8_t)0x01)
/* Resultant angle 20.7 */
#define FXLS8971CF_ORIENT_BF_ZCOMP_ORIENT_ZLOCK_20_7 ((uint8_t)0x02)
/* Resultant angle 24.4 */
#define FXLS8971CF_ORIENT_BF_ZCOMP_ORIENT_ZLOCK_24_4 ((uint8_t)0x03)
/* Resultant angle 28.1 */
#define FXLS8971CF_ORIENT_BF_ZCOMP_ORIENT_ZLOCK_28_1 ((uint8_t)0x04)
/* Resultant angle 32 */
#define FXLS8971CF_ORIENT_BF_ZCOMP_ORIENT_ZLOCK_32_0 ((uint8_t)0x05)
/* Resultant angle 36.1 */
#define FXLS8971CF_ORIENT_BF_ZCOMP_ORIENT_ZLOCK_36_1 ((uint8_t)0x06)
/* Resultant angle 40.4 */
#define FXLS8971CF_ORIENT_BF_ZCOMP_ORIENT_ZLOCK_40_4 ((uint8_t)0x07)
/*------------------------------*/

/*--------------------------------
** Register: ORIENT_THS_REG
** Enum: FXLS8971CF_ORIENT_THS_REG
** --
** Offset : 0x2C Orientation detection state change threshold angle (Portrait/Landscape) and hysteresis settings.
** ------------------------------*/
typedef union
{
  struct
  {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
    uint8_t hys : 3; /* ORIENT_HYS[2:0] */
    uint8_t orient_ths : 5; /* ORIENT_THS[4:0] value */
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
    uint8_t orient_ths : 5; /* ORIENT_THS[4:0] value */
    uint8_t hys : 3; /* ORIENT_HYS[2:0] */
#endif /* DRV_BYTE_ORDER */
  } b;
  uint8_t w;
} fxls8971cf_orient_ths_reg_t;

/*
** ORIENT_THS_REG - Bit field value definitions
*/
#define FXLS8971CF_ORIENT_THS_REG_ORIENT_THS_0_0 ((uint8_t)0x00)  /*  0.0° */
#define FXLS8971CF_ORIENT_THS_REG_ORIENT_THS_1_8 ((uint8_t)0x08)  /*  1.8° */
#define FXLS8971CF_ORIENT_THS_REG_ORIENT_THS_3_8 ((uint8_t)0x10)  /*  3.8° */
#define FXLS8971CF_ORIENT_THS_REG_ORIENT_THS_5_9 ((uint8_t)0x18)  /*  5.9° */
#define FXLS8971CF_ORIENT_THS_REG_ORIENT_THS_8_1 ((uint8_t)0x20)  /*  8.1° */
#define FXLS8971CF_ORIENT_THS_REG_ORIENT_THS_10_5 ((uint8_t)0x28) /*  10.5° */
#define FXLS8971CF_ORIENT_THS_REG_ORIENT_THS_13_0 ((uint8_t)0x30) /*  13.0° */
#define FXLS8971CF_ORIENT_THS_REG_ORIENT_THS_15_6 ((uint8_t)0x38) /*  15.6° */
#define FXLS8971CF_ORIENT_THS_REG_ORIENT_THS_18_4 ((uint8_t)0x40) /*  18.4° */
#define FXLS8971CF_ORIENT_THS_REG_ORIENT_THS_21_4 ((uint8_t)0x48) /*  21.4° */
#define FXLS8971CF_ORIENT_THS_REG_ORIENT_THS_24_4 ((uint8_t)0x50) /*  24.4° */
#define FXLS8971CF_ORIENT_THS_REG_ORIENT_THS_27_6 ((uint8_t)0x58) /*  27.6° */
#define FXLS8971CF_ORIENT_THS_REG_ORIENT_THS_31_0 ((uint8_t)0x60) /*  31.0° */
#define FXLS8971CF_ORIENT_THS_REG_ORIENT_THS_34_4 ((uint8_t)0x68) /*  34.4° */
#define FXLS8971CF_ORIENT_THS_REG_ORIENT_THS_37_9 ((uint8_t)0x70) /*  37.9° */
#define FXLS8971CF_ORIENT_THS_REG_ORIENT_THS_41_4 ((uint8_t)0x78) /*  41.4° */
#define FXLS8971CF_ORIENT_THS_REG_ORIENT_THS_45_0 ((uint8_t)0x80) /*  45.0° */
#define FXLS8971CF_ORIENT_THS_REG_ORIENT_THS_48_6 ((uint8_t)0x88) /*  48.6° */
#define FXLS8971CF_ORIENT_THS_REG_ORIENT_THS_52_1 ((uint8_t)0x90) /*  52.1° */
#define FXLS8971CF_ORIENT_THS_REG_ORIENT_THS_55_6 ((uint8_t)0x98) /*  55.6° */
#define FXLS8971CF_ORIENT_THS_REG_ORIENT_THS_59_0 ((uint8_t)0xa0) /*  59.0° */
#define FXLS8971CF_ORIENT_THS_REG_ORIENT_THS_62_4 ((uint8_t)0xa8) /*  62.4° */
#define FXLS8971CF_ORIENT_THS_REG_ORIENT_THS_65_6 ((uint8_t)0xb0) /*  65.6° */
#define FXLS8971CF_ORIENT_THS_REG_ORIENT_THS_68_6 ((uint8_t)0xb8) /*  68.6° */
#define FXLS8971CF_ORIENT_THS_REG_ORIENT_THS_71_6 ((uint8_t)0xc0) /*  71.6° */
#define FXLS8971CF_ORIENT_THS_REG_ORIENT_THS_74_4 ((uint8_t)0xc8) /*  74.4° */
#define FXLS8971CF_ORIENT_THS_REG_ORIENT_THS_77_0 ((uint8_t)0xd0) /*  77.0° */
#define FXLS8971CF_ORIENT_THS_REG_ORIENT_THS_79_5 ((uint8_t)0xd8) /*  79.5° */
#define FXLS8971CF_ORIENT_THS_REG_ORIENT_THS_81_9 ((uint8_t)0xe0) /*  81.9° */
#define FXLS8971CF_ORIENT_THS_REG_ORIENT_THS_84_1 ((uint8_t)0xe8) /*  84.1° */
#define FXLS8971CF_ORIENT_THS_REG_ORIENT_THS_86_2 ((uint8_t)0xf0) /*  86.2° */
#define FXLS8971CF_ORIENT_THS_REG_ORIENT_THS_88_2 ((uint8_t)0xf8) /*  88.2° */
#define FXLS8971CF_ORIENT_THS_REG_HYS_45_45 ((uint8_t)0x00) /*  L-to-P 45° P-to-L 45° */
#define FXLS8971CF_ORIENT_THS_REG_HYS_49_41 ((uint8_t)0x01) /*  L-to-P 49° P-to-L 41° */
#define FXLS8971CF_ORIENT_THS_REG_HYS_52_38 ((uint8_t)0x02) /*  L-to-P 52° P-to-L 38° */
#define FXLS8971CF_ORIENT_THS_REG_HYS_56_34 ((uint8_t)0x03) /*  L-to-P 56° P-to-L 34° */
#define FXLS8971CF_ORIENT_THS_REG_HYS_59_31 ((uint8_t)0x04) /*  L-to-P 59° P-to-L 31° */
#define FXLS8971CF_ORIENT_THS_REG_HYS_62_28 ((uint8_t)0x05) /*  L-to-P 62° P-to-L 28° */
#define FXLS8971CF_ORIENT_THS_REG_HYS_66_24 ((uint8_t)0x06) /*  L-to-P 66° P-to-L 24° */
#define FXLS8971CF_ORIENT_THS_REG_HYS_69_21 ((uint8_t)0x07) /*  L-to-P 69° P-to-L 21° */
/*------------------------------*/

/*--------------------------------
** Register: SDCD_INT_SRC1
** Enum: FXLS8971CF_SDCD_INT_SRC1
** --
** Offset : 0x2D Sensor data change detection function 1.
** ------------------------------*/
typedef union
{
  struct
  {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
    uint8_t z_ot_pol : 1; /* Z-axis outside of thresholds polarity flag. */
    uint8_t z_ot_ef : 1; /* Z-axis data or delta outside of thresholds event flag. */
    uint8_t y_ot_pol : 1; /* Y-axis outside of thresholds polarity flag. */
    uint8_t y_ot_ef : 1; /* Y-axis data or delta outside of thresholds event flag. */
    uint8_t x_ot_pol : 1; /*  X-axis outside of thresholds polarity flag. */
    uint8_t x_ot_ef : 1; /* X-axis data or delta outside of thresholds event flag. */
    uint8_t _reserved_ : 1;
    uint8_t ot_ea : 1; /* SDCD outside of thresholds event active flag. */
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
    uint8_t ot_ea : 1; /* SDCD outside of thresholds event active flag. */
    uint8_t _reserved_ : 1;
    uint8_t x_ot_ef : 1; /* X-axis data or delta outside of thresholds event flag. */
    uint8_t x_ot_pol : 1; /*  X-axis outside of thresholds polarity flag. */
    uint8_t y_ot_ef : 1; /* Y-axis data or delta outside of thresholds event flag. */
    uint8_t y_ot_pol : 1; /* Y-axis outside of thresholds polarity flag. */
    uint8_t z_ot_ef : 1; /* Z-axis data or delta outside of thresholds event flag. */
    uint8_t z_ot_pol : 1; /* Z-axis outside of thresholds polarity flag. */
#endif /* DRV_BYTE_ORDER */
  } b;
  uint8_t w;
} fxls8971cf_sdcd_int_src1_t;

/*
** SDCD_INT_SRC1 - Bit field value definitions
*/
#define FXLS8971CF_SDCD_INT_SRC1_OT_EA_INSIDE ((uint8_t)0x00)      /*  Event flag not asserted */
#define FXLS8971CF_SDCD_INT_SRC1_OT_EA_OUTSIDE ((uint8_t)0x80)     /*  Event flag asserted. */
#define FXLS8971CF_SDCD_INT_SRC1_X_OT_EF_EVENT_NO ((uint8_t)0x00)  /*  Event has not occured. */
#define FXLS8971CF_SDCD_INT_SRC1_X_OT_EF_EVENT_YES ((uint8_t)0x20) /*  Event has occured. */
#define FXLS8971CF_SDCD_INT_SRC1_X_OT_POL_LT_THS ((uint8_t)0x00)   /*  Less than LTHS. */
#define FXLS8971CF_SDCD_INT_SRC1_X_OT_POL_GT_THS ((uint8_t)0x10)   /*  Greater than UTHS. */
#define FXLS8971CF_SDCD_INT_SRC1_Y_OT_EF_EVENT_NO ((uint8_t)0x00)  /*  Event has not occured. */
#define FXLS8971CF_SDCD_INT_SRC1_Y_OT_EF_EVENT_YES ((uint8_t)0x08) /*  Event has occured. */
#define FXLS8971CF_SDCD_INT_SRC1_Y_OT_POL_LT_THS ((uint8_t)0x00)   /*  Less than LTHS. */
#define FXLS8971CF_SDCD_INT_SRC1_Y_OT_POL_GT_THS ((uint8_t)0x04)   /*  Greater than UTHS. */
#define FXLS8971CF_SDCD_INT_SRC1_Z_OT_EF_EVENT_NO ((uint8_t)0x00)  /*  Event has not occured.  */
#define FXLS8971CF_SDCD_INT_SRC1_Z_OT_EF_EVENT_YES ((uint8_t)0x02) /*  Event has occured. */
#define FXLS8971CF_SDCD_INT_SRC1_Z_OT_POL_LT_THS ((uint8_t)0x00)   /*  Less than LTHS.  */
#define FXLS8971CF_SDCD_INT_SRC1_Z_OT_POL_GT_THS ((uint8_t)0x01)   /*  Greater than UTHS. */
/*------------------------------*/

/*--------------------------------
** Register: SDCD_INT_SRC2
** Enum: FXLS8971CF_SDCD_INT_SRC2
** --
** Offset : 0x2E Sensor data change detection function 2.
** ------------------------------*/
typedef union
{
  struct
  {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
    uint8_t _reserved_ : 1;
    uint8_t z_wt_ef : 1; /* Z-axis data or delta inside of thresholds event flag. */
    uint8_t _reserved_1 : 1;
    uint8_t y_wt_ef : 1; /* Y-axis data or delta inside ofthresholds event flag. */
    uint8_t _reserved_2 : 1;
    uint8_t x_wt_ef : 1; /* X-axis data or delta inside of thresholds event flag. */
    uint8_t _reserved_3 : 1;
    uint8_t wt_ea : 1; /* SDCD within-thresholds event active flag. */
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
    uint8_t wt_ea : 1; /* SDCD within-thresholds event active flag. */
    uint8_t _reserved_3 : 1;
    uint8_t x_wt_ef : 1; /* X-axis data or delta inside of thresholds event flag. */
    uint8_t _reserved_2 : 1;
    uint8_t y_wt_ef : 1; /* Y-axis data or delta inside ofthresholds event flag. */
    uint8_t _reserved_1 : 1;
    uint8_t z_wt_ef : 1; /* Z-axis data or delta inside of thresholds event flag. */
    uint8_t _reserved_ : 1;
#endif /* DRV_BYTE_ORDER */
  } b;
  uint8_t w;
} fxls8971cf_sdcd_int_src2_t;

/*
** SDCD_INT_SRC2 - Bit field value definitions
*/
#define FXLS8971CF_SDCD_INT_SRC2_WT_EA_EVENT_NO ((uint8_t)0x00)    /* Event has not occured. */
#define FXLS8971CF_SDCD_INT_SRC2_WT_EA_EVENT_YES ((uint8_t)0x80)   /* Event has occured. */
#define FXLS8971CF_SDCD_INT_SRC2_X_WT_EF_IN_RANGE ((uint8_t)0x00)  /* X-axis is within range */
#define FXLS8971CF_SDCD_INT_SRC2_X_WT_EF_OUT_RANGE ((uint8_t)0x20) /* X-axis is outside range */
#define FXLS8971CF_SDCD_INT_SRC2_Y_WT_EF_IN_RANGE ((uint8_t)0x00)  /* Y-axis is within range */
#define FXLS8971CF_SDCD_INT_SRC2_Y_WT_EF_OUT_RANGE ((uint8_t)0x08) /*  Y-axis is outside range */
#define FXLS8971CF_SDCD_INT_SRC2_Z_WT_EF_IN_RANGE ((uint8_t)0x00)  /*  Z-axis is within range */
#define FXLS8971CF_SDCD_INT_SRC2_Z_WT_EF_OUT_RANGE ((uint8_t)0x02) /*  Z-axis is outside range */
/*------------------------------*/

/*--------------------------------
** Register: SDCD_CONFIG1
** Enum: FXLS8971CF_SDCD_CONFIG1
** --
** Offset : 0x2F Sensor data change detection function 1 register.
** ------------------------------*/
typedef union
{
  struct
  {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
    uint8_t z_wt_en : 1; /* SDCD function Z-axis within thresholds condition enable. */
    uint8_t y_wt_en : 1; /* SDCD function Y-axis within thresholds condition enable. */
    uint8_t x_wt_en : 1; /*  SDCD function X-axis within thresholds condition enable. */
    uint8_t z_ot_en : 1; /*  SDCD function Z-axis outside of thresholds condition enable. */
    uint8_t y_ot_en : 1; /*  SDCD function Y-axis outside of thresholds condition enable. */
    uint8_t x_ot_en : 1; /*  SDCD function X-axis outside of thresholds condition enable. */
    uint8_t wt_ele : 1; /*  SDCD within thresholds event latch enable. */
    uint8_t ot_ele : 1; /*  SDCD outside of thresholds event latch enable. */
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
    uint8_t ot_ele : 1; /*  SDCD outside of thresholds event latch enable. */
    uint8_t wt_ele : 1; /*  SDCD within thresholds event latch enable. */
    uint8_t x_ot_en : 1; /*  SDCD function X-axis outside of thresholds condition enable. */
    uint8_t y_ot_en : 1; /*  SDCD function Y-axis outside of thresholds condition enable. */
    uint8_t z_ot_en : 1; /*  SDCD function Z-axis outside of thresholds condition enable. */
    uint8_t x_wt_en : 1; /*  SDCD function X-axis within thresholds condition enable. */
    uint8_t y_wt_en : 1; /* SDCD function Y-axis within thresholds condition enable. */
    uint8_t z_wt_en : 1; /* SDCD function Z-axis within thresholds condition enable. */
#endif /* DRV_BYTE_ORDER */
  } b;
  uint8_t w;
} fxls8971cf_sdcd_config1_t;

/*
** SDCD_CONFIG1 - Bit field value definitions
*/
#define FXLS8971CF_SDCD_CONFIG1_OT_ELE_DIS ((uint8_t)0x00) /* OT event flag latching disabled. */
#define FXLS8971CF_SDCD_CONFIG1_OT_ELE_EN ((uint8_t)0x80) /* OT event flag latching enabled. */
#define FXLS8971CF_SDCD_CONFIG1_WT_ELE_DIS ((uint8_t)0x00) /* WT event flag latching disabled. */
#define FXLS8971CF_SDCD_CONFIG1_WT_ELE_EN ((uint8_t)0x40) /* WT event flag latching  enabled. */
#define FXLS8971CF_SDCD_CONFIG1_X_OT_EN_DIS ((uint8_t)0x00) /* X-axis data not used in OT */
#define FXLS8971CF_SDCD_CONFIG1_X_OT_EN_EN ((uint8_t)0x20)  /* X-axis data is used in OT */
#define FXLS8971CF_SDCD_CONFIG1_Y_OT_EN_DIS ((uint8_t)0x00) /* Y-axis data not used in OT */
#define FXLS8971CF_SDCD_CONFIG1_Y_OT_EN_EN ((uint8_t)0x10)  /* Y-axis data is used in OT */
#define FXLS8971CF_SDCD_CONFIG1_Z_OT_EN_DIS ((uint8_t)0x00) /* Z-axis data not used in OT */
#define FXLS8971CF_SDCD_CONFIG1_Z_OT_EN_EN ((uint8_t)0x08)  /* Z-axisdata is used in OT */
#define FXLS8971CF_SDCD_CONFIG1_X_WT_EN_DIS ((uint8_t)0x00) /* X-axis data not used in WT  */
#define FXLS8971CF_SDCD_CONFIG1_X_WT_EN_EN ((uint8_t)0x04)  /* X-axis data is used in WT  */
#define FXLS8971CF_SDCD_CONFIG1_Y_WT_EN_DIS ((uint8_t)0x00) /* Y-axis data not used in WT  */
#define FXLS8971CF_SDCD_CONFIG1_Y_WT_EN_EN ((uint8_t)0x02)  /* Y-axis data is used in WT  */
#define FXLS8971CF_SDCD_CONFIG1_Z_WT_EN_DIS ((uint8_t)0x00) /* Z-axis data not used in WT  */
#define FXLS8971CF_SDCD_CONFIG1_Z_WT_EN_EN ((uint8_t)0x01)  /* Z-axis data is used in WT  */
/*------------------------------*/

/*--------------------------------
** Register: SDCD_CONFIG2
** Enum: FXLS8971CF_SDCD_CONFIG2
** --
** Offset : 0x30 Sensor data change detection function 2 register.
** ------------------------------*/
typedef union
{
  struct
  {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
    uint8_t ref_upd : 1; /*  SDCD synchronous X/Y/Z reference values update bit. */
    uint8_t mode : 1; /*  SDCD input data mode. */
    uint8_t wt_log_sel : 1; /*  SDCD WT event logic selection. */
    uint8_t wt_dbctm : 1; /*  SDCD WT event debounce counter behavior. */
    uint8_t ot_dbctm : 1; /*  SDCD OT event debounce counter behavior. */
    uint8_t ref_updm : 2; /*  SDCD internal reference values update mode. */
    uint8_t sdcd_en : 1; /*  SDCD function. */
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
    uint8_t sdcd_en : 1; /*  SDCD function. */
    uint8_t ref_updm : 2; /*  SDCD internal reference values update mode. */
    uint8_t ot_dbctm : 1; /*  SDCD OT event debounce counter behavior. */
    uint8_t wt_dbctm : 1; /*  SDCD WT event debounce counter behavior. */
    uint8_t wt_log_sel : 1; /*  SDCD WT event logic selection. */
    uint8_t mode : 1; /*  SDCD input data mode. */
    uint8_t ref_upd : 1; /*  SDCD synchronous X/Y/Z reference values update bit. */
#endif /* DRV_BYTE_ORDER */
  } b;
  uint8_t w;
} fxls8971cf_sdcd_config2_t;

/*
** SDCD_CONFIG2 - Bit field value definitions
*/
/* SDCD function is disabled. */
#define FXLS8971CF_SDCD_CONFIG2_SDCD_EN_DIS ((uint8_t)0x00)
/* SDCD function is Enabled. */
#define FXLS8971CF_SDCD_CONFIG2_SDCD_EN_EN ((uint8_t)0x80)
/* The function stores the first 12-bit X/Y/Z decimated and trimmed input data */
#define FXLS8971CF_SDCD_CONFIG2_REF_UPDM_12_BIT ((uint8_t)0x00)
/* The function stores the first decimated and trimmed X/Y/Z acceleration input data */
#define FXLS8971CF_SDCD_CONFIG2_REF_UPDM_FIRST ((uint8_t)0x20)
/* The function updates the SDCD_REF_X/Y/Z values with the current decimated and trimmed X/Y/Z */
#define FXLS8971CF_SDCD_CONFIG2_REF_UPDM_SDCD_REF ((uint8_t)0x40)
/* The function uses a fixed value of 0 for each of the SDCD_REF_X/Y/Z registers */
#define FXLS8971CF_SDCD_CONFIG2_REF_UPDM_FIXED_VAL ((uint8_t)0x60)
/* Debounce counter is decremented by 1 when the OT THS result for enabled axes is false */
#define FXLS8971CF_SDCD_CONFIG2_OT_DBCTM_DECREMENT ((uint8_t)0x00)
/* Debounce counter is cleared whenever the  OT THS result for enabled axes is false */
#define FXLS8971CF_SDCD_CONFIG2_OT_DBCTM_CLEARED ((uint8_t)0x10)
/* Debounce counter is decremented by 1 when the WT THS result for enabled axes is false */
#define FXLS8971CF_SDCD_CONFIG2_WT_DBCTM_DECREMENT ((uint8_t)0x00)
/* Debounce counter is cleared whenever the  OT THS result for enabled axes is false */
#define FXLS8971CF_SDCD_CONFIG2_WT_DBCTM_CLEARED ((uint8_t)0x08)
/* Function uses the logical AND of the enabled axes */
#define FXLS8971CF_SDCD_CONFIG2_WT_LOG_SEL_AND ((uint8_t)0x00)
/* Function uses the logical OR of the enabled axes */
#define FXLS8971CF_SDCD_CONFIG2_WT_LOG_SEL_OR ((uint8_t)0x04)
/* Function uses X, Y, Z acceleration data for the window comparison */
#define FXLS8971CF_SDCD_CONFIG2_MODE_XYZ ((uint8_t)0x00)
/* Function uses Vector magnitude data for the window comparison on the X-axis channel only */
#define FXLS8971CF_SDCD_CONFIG2_MODE_VECM ((uint8_t)0x02)
/* No reference update pending or reference update has completed. */
#define FXLS8971CF_SDCD_CONFIG2_REF_UPD_NO_PENDING ((uint8_t)0x00)
/*  Triggers a synchronous update of the internal X/Y/Z reference registers */
#define FXLS8971CF_SDCD_CONFIG2_REF_UPD_SYNC_UPDATE ((uint8_t)0x01)
/*------------------------------*/

/*--------------------------------
** Register: SDCD_OT_DBCNT
** Enum: FXLS8971CF_SDCD_OT_DBCNT
** --
** Offset : 0x31 Sensor Data Change Detection outside of thresholds condition debounce count value.
** ------------------------------*/
typedef uint8_t fxls8971cf_sdcd_ot_dbcnt_t;

/*--------------------------------
** Register: SDCD_WT_DBCNT
** Enum: FXLS8971CF_SDCD_WT_DBCNT
** --
** Offset : 0x32 Sensor Data Change Detection within thresholds condition debounce count value.
** ------------------------------*/
typedef uint8_t fxls8971cf_sdcd_wt_dbcnt_t;

/*--------------------------------
** Register: SDCD_LTHS_LSB
** Enum: FXLS8971CF_SDCD_LTHS_LSB
** --
** Offset : 0x33 Sensor Data Change Detection lower threshold value LSB.
** ------------------------------*/
typedef uint8_t fxls8971cf_sdcd_lths_lsb_t;

/*--------------------------------
** Register: SDCD_LTHS_MSB
** Enum: FXLS8971CF_SDCD_LTHS_MSB
** --
** Offset : 0x34 Sensor Data change Detection lower threshold value MSB.
** ------------------------------*/
typedef uint8_t fxls8971cf_sdcd_lths_msb_t;

/*--------------------------------
** Register: SDCD_UTHS_LSB
** Enum: FXLS8971CF_SDCD_UTHS_LSB
** --
** Offset : 0x35 Sensor Data change detection upper threshold value LSB.
** ------------------------------*/
typedef uint8_t fxls8971cf_sdcd_uths_lsb_t;

/*--------------------------------
** Register: SDCD_UTHS_MSB
** Enum: FXLS8971CF_SDCD_UTHS_MSB
** --
** Offset : 0x36 Sensor Data change detection upper threshold value MSB.
** ------------------------------*/
typedef uint8_t fxls8971cf_sdcd_uths_msb_t;


/*--------------------------------
** Register: SELF_TEST_CONFIG1
** Enum: FXLS8971CF_SELF_TEST_CONFIG1
** --
** Offset : 0x37 Self Test Configuration function 1 register.
** ------------------------------*/
typedef union
{
  struct
  {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
    uint8_t st_idle : 5; /*  Self-Test Idle phase duration. */
    uint8_t _reserved_ : 3;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
    uint8_t _reserved_ : 3;
    uint8_t st_idle : 5; /*  Self-Test Idle phase duration. */
#endif /* DRV_BYTE_ORDER */
  } b;
  uint8_t w;
} fxls8971cf_self_test_config1_t;

/*--------------------------------
** Register: SELF_TEST_CONFIG2
** Enum: FXLS8971CF_SELF_TEST_CONFIG2
** --
** Offset : 0x38 Self Test Configuration function 2 register.
** ------------------------------*/
typedef union
{
  struct
  {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
    uint8_t st_dec : 4; /*  Self-Test measurement phase decimation factor. */
    uint8_t _reserved_ : 4;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
    uint8_t _reserved_ : 4;
    uint8_t st_dec : 4; /*  Self-Test Idle phase duration. */
#endif /* DRV_BYTE_ORDER */
  } b;
  uint8_t w;
} fxls8971cf_self_test_config2_t;

/*
** SELF_TEST_CONFIG2 - Bit field value definitions
*/
#define FXLS8971CF_SELF_TEST_CONFIG2_ST_DEC_1    ((uint8_t)0x00)
#define FXLS8971CF_SELF_TEST_CONFIG2_ST_DEC_2    ((uint8_t)0x01)
#define FXLS8971CF_SELF_TEST_CONFIG2_ST_DEC_4    ((uint8_t)0x02)
#define FXLS8971CF_SELF_TEST_CONFIG2_ST_DEC_8    ((uint8_t)0x03)
#define FXLS8971CF_SELF_TEST_CONFIG2_ST_DEC_16   ((uint8_t)0x04)
#define FXLS8971CF_SELF_TEST_CONFIG2_ST_DEC_32   ((uint8_t)0x05)
#define FXLS8971CF_SELF_TEST_CONFIG2_ST_DEC_64   ((uint8_t)0x06)
#define FXLS8971CF_SELF_TEST_CONFIG2_ST_DEC_128  ((uint8_t)0x07)
#define FXLS8971CF_SELF_TEST_CONFIG2_ST_DEC_256  ((uint8_t)0x08)
#define FXLS8971CF_SELF_TEST_CONFIG2_ST_DEC_512  ((uint8_t)0x09)
#define FXLS8971CF_SELF_TEST_CONFIG2_ST_DEC_1024 ((uint8_t)0x0a)
#define FXLS8971CF_SELF_TEST_CONFIG2_ST_DEC_2048 ((uint8_t)0x0b)
#define FXLS8971CF_SELF_TEST_CONFIG2_ST_DEC_4096 ((uint8_t)0x0c)

/*!
 * @brief fxls8971cf mode
 */
typedef enum fxls8971cf_mode
{
  STANDBY                = 0,  /* STANDBY Mode*/
  ACTIVE                 = 1,  /* Active  Mode.*/
  SLEEP                  = 2,  /* Sleep  Mode.*/
} fxls8971cf_mode_t;

/* Simple 3-axis container. */
typedef struct
{
  int16_t x;
  int16_t y;
  int16_t z;
} fxls8971cf_data_t;

/* Simple 3-axis container for FIFO. */
typedef struct
{
  int16_t x[FIFO_DEPTH];
  int16_t y[FIFO_DEPTH];
  int16_t z[FIFO_DEPTH];
} fxls8971cf_fifo_data_t;


/* fxls8971cf ASLP Config */
typedef struct
{
  uint8_t aslp_cnt_lsb;      /*  ASLP Count LSB value */
  uint8_t aslp_cnt_msb;      /*  ASLP Count MSB value */
} fxls8971cf_aslp_config_t;

/*
* @brief fxls8971cf FSR bits values
*/
typedef enum
{
  FXLS8971CF_2g = 0,
  FXLS8971CF_4g = 1,
  FXLS8971CF_8g = 2,
  FXLS8971CF_16g = 3,
} fxls8971cf_fs_t;

/*
* @brief fxls8971cf ODR bits values
*/
typedef enum fxls8971cf_odr
{
  FXLS8971CF_ODR_3200HZ  = 0x00,
  FXLS8971CF_ODR_1600HZ  = 0x01,
  FXLS8971CF_ODR_800HZ   = 0x02,
  FXLS8971CF_ODR_400HZ   = 0x03,
  FXLS8971CF_ODR_200HZ   = 0x04,
  FXLS8971CF_ODR_100HZ   = 0x05,
  FXLS8971CF_ODR_50HZ    = 0x06,
  FXLS8971CF_ODR_25HZ    = 0x07,
  FXLS8971CF_ODR_12_5HZ  = 0x08,
  FXLS8971CF_ODR_6_25HZ  = 0x09,
  FXLS8971CF_ODR_3_125HZ = 0x0a,
  FXLS8971CF_ODR_1_563HZ = 0x0b,
  FXLS8971CF_ODR_0_781HZ = 0x0c
} fxls8971cf_odr_t;

/*
* @brief fxls8971cf FIFO mode bits values
*/
typedef enum fxls8971cf_fifo_mode
{
  FXLS8971CF_FIFO_MODE_DISABLED = 0x00,
  FXLS8971CF_FIFO_MODE_STREAM_MODE = 0x01,
  FXLS8971CF_FIFO_MODE_STOP_MODE = 0x02,
  FXLS8971CF_FIFO_MODE_TRIGGER_MODE = 0x03
} fxls8971cf_fifo_mode_t;

/*
* @brief fxls8971cf SDCD Update Mode Ref bits Values
*/
typedef enum fxls8971cf_sdcd_ref_updm
{
  FXLS8971CF_SDCD_REFUPDM_12BIT = 0x00,
  FXLS8971CF_SDCD_REFUPDM_FIRST = 0x01,
  FXLS8971CF_SDCD_REFUPDM_SDCD_REF = 0x02,
  FXLS8971CF_SDCD_REFUPDM_FIXED_VAL = 0x03
} fxls8971cf_sdcd_ref_updm_t;

/*
* @brief fxls8971cf SDCD Embedded Function
*/
typedef enum fxls8971cf_sdcd_config
{
  FXLS8971CF_MOTION_CONFIG,   /*  Motion Wake Up */
  FXLS8971CF_FREEFALL_CONFIG, /*  FreeFall Detection */
  FXLS8971CF_TAP_CONFIG,      /*  Tap Detection.*/
  FXLS8971CF_SHAKE_CONFIG,    /*  Shake detection.*/
  FXLS8971CF_EMBEDDED_FUNCT_END
} fxls8971cf_sdcd_config_t;

typedef enum fxls8971cf_pin_int_route
{
  FXLS8971CF_DRDY_INT_PIN        = 1,
  FXLS8971CF_SDCD_WAKEUP_INT_PIN = 2,
  FXLS8971CF_SDCD_WT_INT_PIN     = 3,
  FXLS8971CF_SDCD_OT_INT_PIN     = 4,
} fxls8971cf_pin_int_route_t;

/**
  * @defgroup  FXLS8971CF_Interfaces_Functions
  * @brief     This section provide a set of functions used to read and
  *            write a generic register of the device.
  *            MANDATORY: return 0 -> no Error.
  * @{
  *
  */

/* Generic read/write */
/**
  * @brief  FXLS8971CF generic device register read
  *
  * @param  ctx   read / write interface definitions(ptr)
  * @param  reg   register to read
  * @param  data  pointer to buffer that store the data read(ptr)
  * @param  len   number of consecutive register to read
  * @retval       Interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t fxls8971cf_read_reg(stmdev_ctx_t *ctx, uint8_t reg, uint8_t *data, uint16_t len);

/**
  * @brief  FXLS8971CF generic device register write
  *
  * @param  ctx   read / write interface definitions(ptr)
  * @param  reg   register to write
  * @param  data  pointer to data to write in register reg(ptr)
  * @param  len   number of consecutive register to write
  * @retval       Interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t fxls8971cf_write_reg(stmdev_ctx_t *ctx, uint8_t reg, const uint8_t *data, uint16_t len);

/**
  * @}
  *
  */

/**
  * @defgroup  FXLS8971CF_Common
  * @brief     This section groups common useful functions.
  * @{
  *
  */

/* Basic control */
/**
  * @brief  FXLS8971CF get device ID
  *
  * @param  ctx   read / write interface definitions(ptr)
  * @param  id    buffer that stores device id
  * @retval       Interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t fxls8971cf_device_id_get(stmdev_ctx_t *ctx, uint8_t *id);

/**
  * @brief  Reset FXLS8971CF device
  *
  * @param  ctx   read / write interface definitions(ptr)
  * @retval       Interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t fxls8971cf_reset(stmdev_ctx_t *ctx);

/**
  * @}
  *
  */

/**
  * @defgroup  FXLS8971CF_Mode
  * @brief     This section groups functions for sensor
  *            mode settings
  * @{
  *
  */

/**
  * @brief  Set mode for FXLS8971CF device
  *
  * @param  ctx   read / write interface definitions(ptr)
  * @param  mode  set mode value (Active or Standby)
  * @retval       Interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t fxls8971cf_mode_set(stmdev_ctx_t *ctx, uint8_t mode);

/**
  * @}
  *
  */

/**
  * @defgroup  FXLS8971CF_Fullscale
  * @brief     This section groups functions for sensor
  *            full scale range settings
  * @{
  *
  */

/* Config helpers */
/**
  * @brief  Set full scale range for FXLS8971CF device
  *
  * @param  ctx   read / write interface definitions(ptr)
  * @param  fs    full scale range value to be set
  * @retval       Interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t fxls8971cf_full_scale_set(stmdev_ctx_t *ctx, fxls8971cf_fs_t val);

/**
  * @brief  Get full scale range for FXLS8971CF device
  *
  * @param  ctx   read / write interface definitions(ptr)
  * @param  fs    pointer to the buffer that stores full scale range value
  * @retval       Interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t fxls8971cf_full_scale_get(stmdev_ctx_t *ctx, fxls8971cf_fs_t *val);

/**
  * @}
  *
  */

/**
  * @defgroup   FXLS8971CF_Datageneration
  * @brief      This section groups all the functions concerning
  *             data generation
  * @{
  *
  */

/**
  * @brief  Set WAKE ODR for FXLS8971CF device
  *
  * @param  ctx   read / write interface definitions(ptr)
  * @param  odr   odr value to be set
  * @retval       Interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t fxls8971cf_wake_odr_set(stmdev_ctx_t *ctx, fxls8971cf_odr_t odr);

/**
  * @brief  Set SLEEP ODR for FXLS8971CF device
  *
  * @param  ctx   read / write interface definitions(ptr)
  * @param  odr   odr value to be set
  * @retval       Interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t fxls8971cf_sleep_odr_set(stmdev_ctx_t *ctx, fxls8971cf_odr_t odr);

/**
  * @brief  Get WAKE ODR for FXLS8971CF device
  *
  * @param  ctx   read / write interface definitions(ptr)
  * @param  odr   pointer to the buffer that stores odr value
  * @retval       Interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t fxls8971cf_wake_odr_get(stmdev_ctx_t *ctx, fxls8971cf_odr_t *odr);

/**
  * @brief  Get SLEEP ODR for FXLS8971CF device
  *
  * @param  ctx   read / write interface definitions(ptr)
  * @param  odr   pointer to the buffer that stores odr value
  * @retval       Interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t fxls8971cf_sleep_odr_get(stmdev_ctx_t *ctx, fxls8971cf_odr_t *odr);

/**
  * @}
  *
  */

/**
  * @defgroup   FXLS8971CF_Dataready_status
  * @brief      This section groups all the functions concerning
  *             data ready event and interrupt
  * @{
  *
  */

/* Check data ready */
/**
  * @brief  Check Data Ready status from FXLS8971CF device
  *
  * @param  ctx   read / write interface definitions(ptr)
  * @param  data_ready   pointer to the buffer that store data ready value
  * @retval       Interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t fxls8971cf_check_data_ready(stmdev_ctx_t *ctx, uint8_t *data_ready);

/**
  * @brief  Enable Data Ready Interrupt for FXLS8971CF device
  *
  * @param  ctx   read / write interface definitions(ptr)
  * @retval       Interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t fxls8971cf_drdy_int_enable(stmdev_ctx_t *ctx);

/**
  * @}
  *
  */

/**
  * @defgroup   FXLS8971CF_FIFO_mode
  * @brief      This section groups all the functions concerning
  *             FIFO mode
  * @{
  *
  */

/* Set FIFO mode */
/**
  * @brief  Set FIFO mode for FXLS8971CF device
  *
  * @param  ctx   read / write interface definitions(ptr)
  * @param  fifo depth   fifo depth value to be set
  * @retval       Interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t fxls8971cf_fifo_mode_set(stmdev_ctx_t *ctx, uint8_t fifo_depth);

/**
  * @brief  Check FIFO status for FXLS8971CF device
  *
  * @param  ctx   read / write interface definitions(ptr)
  * @param  fifo_status   pointer to the buffer that store fifo status value
  * @retval       Interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t fxls8971cf_check_fifo_status(stmdev_ctx_t *ctx, uint8_t *fifo_status);

/**
  * @}
  *
  */

/**
  * @defgroup   FXLS8971CF_SDCD_Config
  * @brief      This section groups all the functions concerning
  *             SDCD config
  * @{
  *
  */

/* Set SDCD Function and ASLP config */
/**
  * @brief  Set SDCD Configuration for FXLS8971CF device for motion events
  *
  * @param  ctx   read / write interface definitions(ptr)
  * @param  sdcd  sdcd function configuration value for chosen motion event
  * @retval       Interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t fxls8971cf_sdcd_config_set(stmdev_ctx_t *ctx, fxls8971cf_sdcd_config_t sdcd_config);

/**
  * @brief  Enable SDCD Wakeup Interrupt for FXLS8971CF device
  *
  * @param  ctx   read / write interface definitions(ptr)
  * @retval       Interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t fxls8971cf_sdcd_wakeup_int_enable(stmdev_ctx_t *ctx);

/**
  * @brief  Enable SDCD WT Interrupt for FXLS8971CF device
  *
  * @param  ctx   read / write interface definitions(ptr)
  * @retval       Interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t fxls8971cf_sdcd_wt_int_enable(stmdev_ctx_t *ctx);

/**
  * @brief  Enable SDCD OT Interrupt for FXLS8971CF device
  *
  * @param  ctx   read / write interface definitions(ptr)
  * @retval       Interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t fxls8971cf_sdcd_ot_int_enable(stmdev_ctx_t *ctx);

/**
  * @brief  Set ASLP (Auto Sleep) counter for FXLS8971CF device
  *
  * @param  ctx   read / write interface definitions(ptr)
  * @param  aslp  ASLP count value to set
  * @retval       Interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t fxls8971cf_aslp_config_set(stmdev_ctx_t *ctx, fxls8971cf_aslp_config_t aslp_config);


/**
  * @}
  *
  */

/**
  * @defgroup  FXLS8971CF_Interrupt_Pins
  * @brief     This section groups all the functions that manage interrupt pins
  * @{
  *
  */

/* Interrupt route */
/**
  * @brief  Route Interrupt for FXLS8971CF device to INT1 pin
  *
  * @param  ctx   read / write interface definitions(ptr)
  * @param  val   Event type that need to be routed to INT1
  * @retval       Interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t fxls8971cf_pin_int1_route_set(stmdev_ctx_t *ctx, fxls8971cf_pin_int_route_t val);

/**
  * @brief  Route Interrupt for FXLS8971CF device to INT2 pin
  *
  * @param  ctx   read / write interface definitions(ptr)
  * @param  val   Event type that need to be routed to INT2
  * @retval       Interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t fxls8971cf_pin_int2_route_set(stmdev_ctx_t *ctx, fxls8971cf_pin_int_route_t val);

/**
  * @}
  *
  */

/**
  * @defgroup  FXLS8971CF_Data_Output
  * @brief     This section groups all the data output functions.
  * @{
  *
  */

/* Read data */
/**
  * @brief  Read raw acceleration data from FXLS8971CF device
  *
  * @param  ctx   read / write interface definitions(ptr)
  * @param  val   pointer to the 16-bit container to store X,Y,Z values
  * @retval       Interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t fxls8971cf_acceleration_raw_get(stmdev_ctx_t *ctx, fxls8971cf_data_t *val);

/**
  * @brief  Read raw acceleration data from HW FIFO of FXLS8971CF device
  *
  * @param  ctx   read / write interface definitions(ptr)
  * @param  val   pointer to the 16-bit container to store X,Y,Z values
  * @retval       Interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t fxls8971cf_acceleration_raw_fifo_get(stmdev_ctx_t *ctx, fxls8971cf_fifo_data_t *val,
                                             uint8_t sample_cnt);

/**
  * @}
  *
  */

/**
  * @defgroup  FXLS8971CF_Events
  * @brief     This section groups all the read events functions.
  * @{
  *
  */

/* Read Events */
/**
  * @brief  Get Interrupt Status from FXLS8971CF device
  *
  * @param  ctx   read / write interface definitions(ptr)
  * @param  int_status   pointer to the 16-bit container to store int status
  * @retval       Interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t fxls8971cf_interrupt_status_get(stmdev_ctx_t *ctx, uint8_t *int_status);

/**
  * @brief  Get sys mode from FXLS8971CF device
  *
  * @param  ctx   read / write interface definitions(ptr)
  * @param  int_status   pointer to the 16-bit container to store int status
  * @retval       Interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t fxls8971cf_sys_mode_get(stmdev_ctx_t *ctx, uint8_t *sys_mode);

/**
  * @}
  *
  */

/**
  * @defgroup  FXLS8971CF_Sensitivity
  * @brief     These functions convert raw-data into engineering units.
  * @{
  *
  */

/* Raw to g conversions – LSB/g values */
float fxls8971cf_from_raw_to_2g(int16_t lsb);
float fxls8971cf_from_raw_to_4g(int16_t lsb);
float fxls8971cf_from_raw_to_8g(int16_t lsb);
float fxls8971cf_from_raw_to_16g(int16_t lsb);

/**
  * @}
  *
  */

#ifdef __cplusplus
}
#endif

#endif /* FXLS8971CF_REG_H */
