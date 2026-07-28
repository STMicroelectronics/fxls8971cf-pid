/**
  ******************************************************************************
  * @file    fxls8974cf_reg.c
  * @author  Sensors Software Solution Team
  * @brief   FXLS8974CF driver file
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

#include "fxls8974cf_reg.h"

/**
  * @defgroup    FXLS8974CF
  * @brief       This file provides a set of functions needed to drive the
  *              fxls8974cf 3-axis low-g accelerometer.
  * @{
  *
  */

int32_t fxls8974cf_read_reg(stmdev_ctx_t *ctx, uint8_t reg,
                            uint8_t *data, uint16_t len)
{
  int32_t ret;

  if (ctx == NULL || ctx->read_reg == NULL)
  {
    return -1;
  }

  ret = ctx->read_reg(ctx->handle, reg, data, len);

  return ret;
}

int32_t fxls8974cf_write_reg(stmdev_ctx_t *ctx, uint8_t reg,
                             const uint8_t *data, uint16_t len)
{
  int32_t ret;

  if (ctx == NULL || ctx->write_reg == NULL)
  {
    return -1;
  }

  ret = ctx->write_reg(ctx->handle, reg, data, len);

  return ret;
}

int32_t fxls8974cf_device_id_get(stmdev_ctx_t *ctx, uint8_t *id)
{
  if (id == NULL)
  {
    return -1;
  }

  return fxls8974cf_read_reg(ctx, FXLS8974CF_WHO_AM_I, id, 1);

}

int32_t fxls8974cf_reset(stmdev_ctx_t *ctx)
{
  int32_t ret;
  fxls8974cf_sens_config1_t reg;

  fxls8974cf_read_reg(ctx, FXLS8974CF_SENS_CONFIG1, (uint8_t *)&reg, 1);
  reg.b.rst = 1U;
  ret = fxls8974cf_write_reg(ctx, FXLS8974CF_SENS_CONFIG1, (uint8_t *)&reg, 1);
  if (ret != 0)
  {
    return ret;
  }

  if (ctx != NULL && ctx->mdelay != NULL)
  {
    ctx->mdelay(10U);
  }

  return ret;
}

int32_t fxls8974cf_mode_set(stmdev_ctx_t *ctx, uint8_t mode)
{
  int32_t ret;

  fxls8974cf_sens_config1_t reg;

  ret = fxls8974cf_read_reg(ctx, FXLS8974CF_SENS_CONFIG1, (uint8_t *)&reg, 1);
  if (ret != 0)
  {
    return ret;
  }
  reg.b.active = (mode ? 1U : 0U);

  return fxls8974cf_write_reg(ctx, FXLS8974CF_SENS_CONFIG1, (uint8_t *)&reg, 1);
}

int32_t fxls8974cf_full_scale_set(stmdev_ctx_t *ctx, fxls8974cf_fs_t fs)
{
  int32_t ret;

  fxls8974cf_sens_config1_t reg;

  ret = fxls8974cf_read_reg(ctx, FXLS8974CF_SENS_CONFIG1, (uint8_t *)&reg, 1);
  if (ret != 0)
  {
    return ret;
  }
  reg.b.fsr = (uint8_t) fs;

  fxls8974cf_mode_set(ctx, STANDBY);
  ret = fxls8974cf_write_reg(ctx, FXLS8974CF_SENS_CONFIG1, (uint8_t *)&reg, 1);
  fxls8974cf_mode_set(ctx, ACTIVE);

  return ret;
}

int32_t fxls8974cf_full_scale_get(stmdev_ctx_t *ctx, fxls8974cf_fs_t *fs)
{
  int32_t ret;

  fxls8974cf_sens_config1_t reg;

  ret = fxls8974cf_read_reg(ctx, FXLS8974CF_SENS_CONFIG1, (uint8_t *)&reg, 1);
  if (ret != 0)
  {
    return ret;
  }

  if (fs == NULL)
  {
    return -1;
  }

  switch (reg.b.fsr)
  {
    case 0:

      *fs = FXLS8974CF_2g;
      break;

    case 1:

      *fs = FXLS8974CF_4g;
      break;

    case 2:

      *fs = FXLS8974CF_8g;
      break;

    case 3:

      *fs = FXLS8974CF_16g;
      break;

    default:
      ret = -1;
      break;
  }

  return ret;
}

int32_t fxls8974cf_wake_odr_set(stmdev_ctx_t *ctx, fxls8974cf_odr_t odr)
{
  int32_t ret;

  fxls8974cf_sens_config3_t reg;

  ret = fxls8974cf_read_reg(ctx, FXLS8974CF_SENS_CONFIG3, (uint8_t *)&reg, 1);
  if (ret != 0)
  {
    return ret;
  }
  reg.b.wake_odr = (uint8_t)odr;

  fxls8974cf_mode_set(ctx, STANDBY);
  ret = fxls8974cf_write_reg(ctx, FXLS8974CF_SENS_CONFIG3, (uint8_t *)&reg, 1);
  fxls8974cf_mode_set(ctx, ACTIVE);

  return ret;
}

int32_t fxls8974cf_sleep_odr_set(stmdev_ctx_t *ctx, fxls8974cf_odr_t odr)
{
  int32_t ret;

  fxls8974cf_sens_config3_t reg;

  ret = fxls8974cf_read_reg(ctx, FXLS8974CF_SENS_CONFIG3, (uint8_t *)&reg, 1);
  if (ret != 0)
  {
    return ret;
  }
  reg.b.sleep_odr = (uint8_t)odr;

  fxls8974cf_mode_set(ctx, STANDBY);
  ret = fxls8974cf_write_reg(ctx, FXLS8974CF_SENS_CONFIG3, (uint8_t *)&reg, 1);
  fxls8974cf_mode_set(ctx, ACTIVE);

  return ret;
}

int32_t fxls8974cf_wake_odr_get(stmdev_ctx_t *ctx, fxls8974cf_odr_t *odr)
{
  int32_t ret;

  fxls8974cf_sens_config3_t reg;

  ret = fxls8974cf_read_reg(ctx, FXLS8974CF_SENS_CONFIG3, (uint8_t *)&reg, 1);
  if (ret != 0)
  {
    return ret;
  }

  if (odr == NULL)
  {
    return -1;
  }

  switch (reg.b.wake_odr)
  {
    case 0x00:

      *odr = FXLS8974CF_ODR_3200HZ;
      break;

    case 0x10:

      *odr = FXLS8974CF_ODR_1600HZ;
      break;

    case 0x20:

      *odr = FXLS8974CF_ODR_800HZ;
      break;

    case 0x30:

      *odr = FXLS8974CF_ODR_400HZ;
      break;

    case 0x40:

      *odr = FXLS8974CF_ODR_200HZ;
      break;

    case 0x50:

      *odr = FXLS8974CF_ODR_100HZ;
      break;

    case 0x60:

      *odr = FXLS8974CF_ODR_50HZ;
      break;

    case 0x70:

      *odr = FXLS8974CF_ODR_25HZ;
      break;

    case 0x80:

      *odr = FXLS8974CF_ODR_12_5HZ;
      break;

    case 0x90:

      *odr = FXLS8974CF_ODR_6_25HZ;
      break;

    case 0xA0:

      *odr = FXLS8974CF_ODR_3_125HZ;
      break;

    case 0xB0:

      *odr = FXLS8974CF_ODR_1_563HZ;
      break;

    case 0xC0:

      *odr = FXLS8974CF_ODR_0_781HZ;
      break;

    default:
      ret = -1;
      break;
  }

  return ret;
}

int32_t fxls8974cf_sleep_odr_get(stmdev_ctx_t *ctx, fxls8974cf_odr_t *odr)
{
  int32_t ret;

  fxls8974cf_sens_config3_t reg;

  ret = fxls8974cf_read_reg(ctx, FXLS8974CF_SENS_CONFIG3, (uint8_t *)&reg, 1);
  if (ret != 0)
  {
    return ret;
  }

  if (odr == NULL)
  {
    return -1;
  }

  switch (reg.b.sleep_odr)
  {
    case 0x00:

      *odr = FXLS8974CF_ODR_3200HZ;
      break;

    case 0x01:

      *odr = FXLS8974CF_ODR_1600HZ;
      break;

    case 0x02:

      *odr = FXLS8974CF_ODR_800HZ;
      break;

    case 0x03:

      *odr = FXLS8974CF_ODR_400HZ;
      break;

    case 0x04:

      *odr = FXLS8974CF_ODR_200HZ;
      break;

    case 0x05:

      *odr = FXLS8974CF_ODR_100HZ;
      break;

    case 0x06:

      *odr = FXLS8974CF_ODR_50HZ;
      break;

    case 0x07:

      *odr = FXLS8974CF_ODR_25HZ;
      break;

    case 0x08:

      *odr = FXLS8974CF_ODR_12_5HZ;
      break;

    case 0x09:

      *odr = FXLS8974CF_ODR_6_25HZ;
      break;

    case 0x0A:

      *odr = FXLS8974CF_ODR_3_125HZ;
      break;

    case 0x0B:

      *odr = FXLS8974CF_ODR_1_563HZ;
      break;

    case 0x0C:

      *odr = FXLS8974CF_ODR_0_781HZ;
      break;

    default:
      ret = -1;
      break;
  }

  return ret;
}

int32_t fxls8974cf_check_data_ready(stmdev_ctx_t *ctx, uint8_t *data_ready)
{
  if (data_ready == NULL)
  {
    return -1;
  }

  return fxls8974cf_read_reg(ctx, FXLS8974CF_INT_STATUS, data_ready, 1);
}

int32_t fxls8974cf_drdy_int_enable(stmdev_ctx_t *ctx)
{
  int32_t ret;

  fxls8974cf_int_en_t reg;

  ret = fxls8974cf_read_reg(ctx, FXLS8974CF_INT_EN, (uint8_t *)&reg, 1);
  if (ret != 0)
  {
    return ret;
  }
  reg.b.drdy_en = FXLS8974_SETB;

  fxls8974cf_mode_set(ctx, STANDBY);
  ret = fxls8974cf_write_reg(ctx, FXLS8974CF_INT_EN, (uint8_t *)&reg, 1);
  fxls8974cf_mode_set(ctx, ACTIVE);

  return ret;
}

int32_t fxls8974cf_sdcd_wakeup_int_enable(stmdev_ctx_t *ctx)
{
  int32_t ret;

  fxls8974cf_int_en_t reg;

  ret = fxls8974cf_read_reg(ctx, FXLS8974CF_INT_EN, (uint8_t *)&reg, 1);
  if (ret != 0)
  {
    return ret;
  }
  reg.b.wake_out_en = FXLS8974_SETB;

  fxls8974cf_mode_set(ctx, STANDBY);
  ret = fxls8974cf_write_reg(ctx, FXLS8974CF_INT_EN, (uint8_t *)&reg, 1);
  fxls8974cf_mode_set(ctx, ACTIVE);

  return ret;
}

int32_t fxls8974cf_sdcd_wt_int_enable(stmdev_ctx_t *ctx)
{
  int32_t ret;

  fxls8974cf_int_en_t reg;

  ret = fxls8974cf_read_reg(ctx, FXLS8974CF_INT_EN, (uint8_t *)&reg, 1);
  if (ret != 0)
  {
    return ret;
  }
  reg.b.sdcd_wt_en = FXLS8974_SETB;

  fxls8974cf_mode_set(ctx, STANDBY);
  ret = fxls8974cf_write_reg(ctx, FXLS8974CF_INT_EN, (uint8_t *)&reg, 1);
  fxls8974cf_mode_set(ctx, ACTIVE);

  return ret;
}

int32_t fxls8974cf_sdcd_ot_int_enable(stmdev_ctx_t *ctx)
{
  int32_t ret;

  fxls8974cf_int_en_t reg;

  ret = fxls8974cf_read_reg(ctx, FXLS8974CF_INT_EN, (uint8_t *)&reg, 1);
  if (ret != 0)
  {
    return ret;
  }
  reg.b.sdcd_ot_en = FXLS8974_SETB;

  fxls8974cf_mode_set(ctx, STANDBY);
  ret = fxls8974cf_write_reg(ctx, FXLS8974CF_INT_EN, (uint8_t *)&reg, 1);
  fxls8974cf_mode_set(ctx, ACTIVE);

  return ret;
}

int32_t fxls8974cf_pin_int1_route_set(stmdev_ctx_t *ctx, fxls8974cf_pin_int_route_t val)
{
  int32_t ret;

  fxls8974cf_int_pin_sel_t reg;

  ret = fxls8974cf_read_reg(ctx, FXLS8974CF_INT_PIN_SEL, (uint8_t *)&reg, 1);
  if (ret != 0)
  {
    return ret;
  }

  switch (val)
  {
    case FXLS8974CF_DRDY_INT_PIN:

      reg.b.drdy_int2 = FXLS8974_RSTB;

      fxls8974cf_mode_set(ctx, STANDBY);
      ret = fxls8974cf_write_reg(ctx, FXLS8974CF_INT_PIN_SEL, (uint8_t *)&reg, 1);
      fxls8974cf_mode_set(ctx, ACTIVE);

      break;

    case FXLS8974CF_SDCD_WAKEUP_INT_PIN:

      reg.b.wk_out_int2 = FXLS8974_RSTB;

      fxls8974cf_mode_set(ctx, STANDBY);
      ret = fxls8974cf_write_reg(ctx, FXLS8974CF_INT_PIN_SEL, (uint8_t *)&reg, 1);
      fxls8974cf_mode_set(ctx, ACTIVE);
      break;

    case FXLS8974CF_SDCD_WT_INT_PIN:

      reg.b.sdcd_wt_int2 = FXLS8974_RSTB;

      fxls8974cf_mode_set(ctx, STANDBY);
      ret = fxls8974cf_write_reg(ctx, FXLS8974CF_INT_PIN_SEL, (uint8_t *)&reg, 1);
      fxls8974cf_mode_set(ctx, ACTIVE);
      break;

    case FXLS8974CF_SDCD_OT_INT_PIN:

      reg.b.sdcd_ot_int2 = FXLS8974_RSTB;

      fxls8974cf_mode_set(ctx, STANDBY);
      ret = fxls8974cf_write_reg(ctx, FXLS8974CF_INT_PIN_SEL, (uint8_t *)&reg, 1);
      fxls8974cf_mode_set(ctx, ACTIVE);
      break;

    default:
      ret = -1;
      break;
  }

  return ret;
}

int32_t fxls8974cf_pin_int2_route_set(stmdev_ctx_t *ctx, fxls8974cf_pin_int_route_t val)
{
  int32_t ret;

  fxls8974cf_int_pin_sel_t reg;

  ret = fxls8974cf_read_reg(ctx, FXLS8974CF_INT_PIN_SEL, (uint8_t *)&reg, 1);
  if (ret != 0)
  {
    return ret;
  }

  switch (val)
  {
    case FXLS8974CF_DRDY_INT_PIN:

      reg.b.drdy_int2 = FXLS8974_SETB;

      fxls8974cf_mode_set(ctx, STANDBY);
      ret = fxls8974cf_write_reg(ctx, FXLS8974CF_INT_PIN_SEL, (uint8_t *)&reg, 1);
      fxls8974cf_mode_set(ctx, ACTIVE);

      break;

    case FXLS8974CF_SDCD_WAKEUP_INT_PIN:

      reg.b.wk_out_int2 = FXLS8974_SETB;

      fxls8974cf_mode_set(ctx, STANDBY);
      ret = fxls8974cf_write_reg(ctx, FXLS8974CF_INT_PIN_SEL, (uint8_t *)&reg, 1);
      fxls8974cf_mode_set(ctx, ACTIVE);
      break;

    case FXLS8974CF_SDCD_WT_INT_PIN:

      reg.b.sdcd_wt_int2 = FXLS8974_SETB;

      fxls8974cf_mode_set(ctx, STANDBY);
      ret = fxls8974cf_write_reg(ctx, FXLS8974CF_INT_PIN_SEL, (uint8_t *)&reg, 1);
      fxls8974cf_mode_set(ctx, ACTIVE);
      break;

    case FXLS8974CF_SDCD_OT_INT_PIN:

      reg.b.sdcd_ot_int2 = FXLS8974_SETB;

      fxls8974cf_mode_set(ctx, STANDBY);
      ret = fxls8974cf_write_reg(ctx, FXLS8974CF_INT_PIN_SEL, (uint8_t *)&reg, 1);
      fxls8974cf_mode_set(ctx, ACTIVE);
      break;

    default:
      ret = -1;
      break;
  }

  return ret;
}

int32_t fxls8974cf_fifo_mode_set(stmdev_ctx_t *ctx, uint8_t fifo_depth)
{
  int32_t ret;

  if (MAX_FIFO_DEPTH < fifo_depth)
  {
    return -1;
  }

  fxls8974cf_buf_config1_t fifo_config1;
  fxls8974cf_buf_config2_t fifo_config2;

  ret = fxls8974cf_read_reg(ctx, FXLS8974CF_BUF_CONFIG1, (uint8_t *)&fifo_config1, 1);
  if (ret != 0)
  {
    return ret;
  }
  fifo_config1.b.buf_type = FXLS8974_RSTB;
  fifo_config1.b.buf_mode = FXLS8974CF_FIFO_MODE_STOP_MODE;

  ret = fxls8974cf_read_reg(ctx, FXLS8974CF_BUF_CONFIG2, (uint8_t *)&fifo_config2, 1);
  if (ret != 0)
  {
    return ret;
  }
  fifo_config2.b.buf_wmrk = fifo_depth;

  fxls8974cf_mode_set(ctx, STANDBY);
  ret = fxls8974cf_write_reg(ctx, FXLS8974CF_BUF_CONFIG1, (uint8_t *)&fifo_config1, 1);
  if (ret != 0)
  {
    return ret;
  }
  ret = fxls8974cf_write_reg(ctx, FXLS8974CF_BUF_CONFIG2, (uint8_t *)&fifo_config2, 1);
  fxls8974cf_mode_set(ctx, ACTIVE);

  return ret;
}

int32_t fxls8974cf_check_fifo_status(stmdev_ctx_t *ctx, uint8_t *fifo_status)
{
  if (fifo_status == NULL)
  {
    return -1;
  }

  return fxls8974cf_read_reg(ctx, FXLS8974CF_BUF_STATUS, fifo_status, 1);

}

int32_t fxls8974cf_sdcd_config_set(stmdev_ctx_t *ctx, fxls8974cf_sdcd_config_t sdcd_config)
{
  int32_t ret;

  fxls8974cf_sdcd_config1_t  sdcd_config1;
  fxls8974cf_sdcd_config2_t  sdcd_config2;
  fxls8974cf_sdcd_ot_dbcnt_t ot_dbcnt;
  fxls8974cf_sdcd_wt_dbcnt_t wt_dbcnt;
  fxls8974cf_sdcd_lths_lsb_t sdcd_lths_lsb;
  fxls8974cf_sdcd_lths_msb_t sdcd_lths_msb;
  fxls8974cf_sdcd_uths_lsb_t sdcd_uths_lsb;
  fxls8974cf_sdcd_uths_msb_t sdcd_uths_msb;

  switch (sdcd_config)
  {
    case FXLS8974CF_MOTION_CONFIG:

      ret = fxls8974cf_read_reg(ctx, FXLS8974CF_SDCD_CONFIG1, (uint8_t *)&sdcd_config1, 1);
      if (ret != 0)
      {
        return ret;
      }
      /* Enable SDCD OT for all 3 axes X, Y & Z and within-thresholds event latch disabled. */
      sdcd_config1.b.x_ot_en = FXLS8974_SETB;
      sdcd_config1.b.y_ot_en = FXLS8974_SETB;
      sdcd_config1.b.z_ot_en = FXLS8974_SETB;
      sdcd_config1.b.ot_ele = FXLS8974_RSTB;

      ret = fxls8974cf_read_reg(ctx, FXLS8974CF_SDCD_CONFIG2, (uint8_t *)&sdcd_config2, 1);
      if (ret != 0)
      {
        return ret;
      }
      /* Enable SDCD function and Relative Data (N)/Data (N-1) mode for data change detection */
      sdcd_config2.b.sdcd_en = FXLS8974_SETB;
      sdcd_config2.b.ref_updm = FXLS8974CF_SDCD_REFUPDM_SDCD_REF;

      ret = fxls8974cf_read_reg(ctx, FXLS8974CF_SDCD_OT_DBCNT, (uint8_t *)&ot_dbcnt, 1);
      if (ret != 0)
      {
        return ret;
      }
      /* Set the SDCD_OT debounce count to 0 */
      ot_dbcnt = 0;

      ret = fxls8974cf_read_reg(ctx, FXLS8974CF_SDCD_LTHS_LSB, (uint8_t *)&sdcd_lths_lsb, 1);
      ret += fxls8974cf_read_reg(ctx, FXLS8974CF_SDCD_LTHS_MSB, (uint8_t *)&sdcd_lths_msb, 1);
      ret += fxls8974cf_read_reg(ctx, FXLS8974CF_SDCD_UTHS_LSB, (uint8_t *)&sdcd_uths_lsb, 1);
      ret += fxls8974cf_read_reg(ctx, FXLS8974CF_SDCD_UTHS_MSB, (uint8_t *)&sdcd_uths_msb, 1);
      if (ret != 0)
      {
        return ret;
      }

      /* Set the SDCD lower and upper thresholds to +/-100mg*/
      sdcd_lths_lsb = 0xCC;
      sdcd_lths_msb = 0xFF;
      sdcd_uths_lsb = 0x34;
      sdcd_uths_msb = 0x00;

      fxls8974cf_mode_set(ctx, STANDBY);
      ret = fxls8974cf_write_reg(ctx, FXLS8974CF_SDCD_CONFIG1, (uint8_t *)&sdcd_config1, 1);
      ret += fxls8974cf_write_reg(ctx, FXLS8974CF_SDCD_CONFIG2, (uint8_t *)&sdcd_config2, 1);
      ret += fxls8974cf_write_reg(ctx, FXLS8974CF_SDCD_OT_DBCNT, (uint8_t *)&ot_dbcnt, 1);
      ret += fxls8974cf_write_reg(ctx, FXLS8974CF_SDCD_LTHS_LSB, (uint8_t *)&sdcd_lths_lsb, 1);
      ret += fxls8974cf_write_reg(ctx, FXLS8974CF_SDCD_LTHS_MSB, (uint8_t *)&sdcd_lths_msb, 1);
      ret += fxls8974cf_write_reg(ctx, FXLS8974CF_SDCD_UTHS_LSB, (uint8_t *)&sdcd_uths_lsb, 1);
      ret += fxls8974cf_write_reg(ctx, FXLS8974CF_SDCD_UTHS_MSB, (uint8_t *)&sdcd_uths_msb, 1);
      fxls8974cf_mode_set(ctx, ACTIVE);

      break;

    case FXLS8974CF_FREEFALL_CONFIG:

      ret = fxls8974cf_read_reg(ctx, FXLS8974CF_SDCD_CONFIG1, (uint8_t *)&sdcd_config1, 1);
      /* Enable SDCD WT for all 3 axes X, Y & Z and within-thresholds event latch disabled. */
      sdcd_config1.b.x_wt_en = FXLS8974_SETB;
      sdcd_config1.b.y_wt_en = FXLS8974_SETB;
      sdcd_config1.b.z_wt_en = FXLS8974_SETB;

      ret = fxls8974cf_read_reg(ctx, FXLS8974CF_SDCD_CONFIG2, (uint8_t *)&sdcd_config2, 1);

      /* Enable SDCD function, enable absolute reference mode and set WT logic selection and
       * debounce behavior is set to clear immediately when threshold criteria evaluates to false */
      sdcd_config2.b.sdcd_en = FXLS8974_SETB;
      sdcd_config2.b.ref_updm = FXLS8974CF_SDCD_REFUPDM_FIXED_VAL;
      sdcd_config2.b.wt_log_sel = FXLS8974_RSTB;
      sdcd_config2.b.wt_dbctm = FXLS8974_SETB;

      ret = fxls8974cf_read_reg(ctx, FXLS8974CF_SDCD_WT_DBCNT, (uint8_t *)&wt_dbcnt, 1);
      /* Set the SDCD_OT debounce count to 10 */
      wt_dbcnt = 0x0A;

      ret = fxls8974cf_read_reg(ctx, FXLS8974CF_SDCD_LTHS_LSB, (uint8_t *)&sdcd_lths_lsb, 1);
      ret += fxls8974cf_read_reg(ctx, FXLS8974CF_SDCD_LTHS_MSB, (uint8_t *)&sdcd_lths_msb, 1);
      ret += fxls8974cf_read_reg(ctx, FXLS8974CF_SDCD_UTHS_LSB, (uint8_t *)&sdcd_uths_lsb, 1);
      ret += fxls8974cf_read_reg(ctx, FXLS8974CF_SDCD_UTHS_MSB, (uint8_t *)&sdcd_uths_msb, 1);
      if (ret != 0)
      {
        return ret;
      }
      /* Set the SDCD lower and upper thresholds to +/-200mg*/
      sdcd_lths_lsb = 0x99;
      sdcd_lths_msb = 0xFF;
      sdcd_uths_lsb = 0x67;
      sdcd_uths_msb = 0x00;

      fxls8974cf_mode_set(ctx, STANDBY);
      ret = fxls8974cf_write_reg(ctx, FXLS8974CF_SDCD_CONFIG1, (uint8_t *)&sdcd_config1, 1);
      ret += fxls8974cf_write_reg(ctx, FXLS8974CF_SDCD_CONFIG2, (uint8_t *)&sdcd_config2, 1);
      ret += fxls8974cf_write_reg(ctx, FXLS8974CF_SDCD_WT_DBCNT, (uint8_t *)&wt_dbcnt, 1);
      ret += fxls8974cf_write_reg(ctx, FXLS8974CF_SDCD_LTHS_LSB, (uint8_t *)&sdcd_lths_lsb, 1);
      ret += fxls8974cf_write_reg(ctx, FXLS8974CF_SDCD_LTHS_MSB, (uint8_t *)&sdcd_lths_msb, 1);
      ret += fxls8974cf_write_reg(ctx, FXLS8974CF_SDCD_UTHS_LSB, (uint8_t *)&sdcd_uths_lsb, 1);
      ret += fxls8974cf_write_reg(ctx, FXLS8974CF_SDCD_UTHS_MSB, (uint8_t *)&sdcd_uths_msb, 1);
      fxls8974cf_mode_set(ctx, ACTIVE);
      break;

    case FXLS8974CF_TAP_CONFIG:

      ret = fxls8974cf_read_reg(ctx, FXLS8974CF_SDCD_CONFIG1, (uint8_t *)&sdcd_config1, 1);
      /* Enable SDCD OT for all 3 axes X, Y & Z and within-thresholds event latch disabled. */
      sdcd_config1.b.x_ot_en = FXLS8974_SETB;
      sdcd_config1.b.y_ot_en = FXLS8974_SETB;
      sdcd_config1.b.z_ot_en = FXLS8974_SETB;

      ret = fxls8974cf_read_reg(ctx, FXLS8974CF_SDCD_CONFIG2, (uint8_t *)&sdcd_config2, 1);
      /* Enable SDCD function and Relative Data (N)/Data (N-1) mode for data change detection */
      sdcd_config2.b.sdcd_en = FXLS8974_SETB;
      sdcd_config2.b.ref_updm = FXLS8974CF_SDCD_REFUPDM_SDCD_REF;

      ret = fxls8974cf_read_reg(ctx, FXLS8974CF_SDCD_OT_DBCNT, (uint8_t *)&ot_dbcnt, 1);
      /* Set the SDCD_OT debounce count to 0 */
      ot_dbcnt = 0;

      ret = fxls8974cf_read_reg(ctx, FXLS8974CF_SDCD_LTHS_LSB, (uint8_t *)&sdcd_lths_lsb, 1);
      ret += fxls8974cf_read_reg(ctx, FXLS8974CF_SDCD_LTHS_MSB, (uint8_t *)&sdcd_lths_msb, 1);
      ret += fxls8974cf_read_reg(ctx, FXLS8974CF_SDCD_UTHS_LSB, (uint8_t *)&sdcd_uths_lsb, 1);
      ret += fxls8974cf_read_reg(ctx, FXLS8974CF_SDCD_UTHS_MSB, (uint8_t *)&sdcd_uths_msb, 1);
      if (ret != 0)
      {
        return ret;
      }
      /* Set the SDCD lower and upper thresholds to +/-2g*/
      sdcd_lths_lsb = 0xFF;
      sdcd_lths_msb = 0xFB;
      sdcd_uths_lsb = 0x01;
      sdcd_uths_msb = 0x04;

      fxls8974cf_mode_set(ctx, STANDBY);
      ret = fxls8974cf_write_reg(ctx, FXLS8974CF_SDCD_CONFIG1, (uint8_t *)&sdcd_config1, 1);
      ret += fxls8974cf_write_reg(ctx, FXLS8974CF_SDCD_CONFIG2, (uint8_t *)&sdcd_config2, 1);
      ret += fxls8974cf_write_reg(ctx, FXLS8974CF_SDCD_OT_DBCNT, (uint8_t *)&ot_dbcnt, 1);
      ret += fxls8974cf_write_reg(ctx, FXLS8974CF_SDCD_LTHS_LSB, (uint8_t *)&sdcd_lths_lsb, 1);
      ret += fxls8974cf_write_reg(ctx, FXLS8974CF_SDCD_LTHS_MSB, (uint8_t *)&sdcd_lths_msb, 1);
      ret += fxls8974cf_write_reg(ctx, FXLS8974CF_SDCD_UTHS_LSB, (uint8_t *)&sdcd_uths_lsb, 1);
      ret += fxls8974cf_write_reg(ctx, FXLS8974CF_SDCD_UTHS_MSB, (uint8_t *)&sdcd_uths_msb, 1);
      fxls8974cf_mode_set(ctx, ACTIVE);
      break;

    case FXLS8974CF_SHAKE_CONFIG:
      break;

    default:
      ret = -1;
      break;
  }

  return ret;
}

int32_t fxls8974cf_aslp_config_set(stmdev_ctx_t *ctx, fxls8974cf_aslp_config_t aslp_config)
{
  int32_t ret;

  fxls8974cf_sens_config4_t sens_config4;
  fxls8974cf_aslp_count_lsb_t count_lsb;
  fxls8974cf_aslp_count_msb_t count_msb;

  ret = fxls8974cf_read_reg(ctx, FXLS8974CF_SENS_CONFIG4, (uint8_t *)&sens_config4, 1);
  if (ret != 0)
  {
    return ret;
  }
  /* Enable SDCD outside of thresholds event Auto-WAKE/SLEEP transition source enable. */
  sens_config4.b.wk_sdcd_ot = FXLS8974_SETB;
  sens_config4.b.int_pol = FXLS8974_SETB;

  ret = fxls8974cf_read_reg(ctx, FXLS8974CF_ASLP_COUNT_LSB, (uint8_t *)&count_lsb, 1);
  if (ret != 0)
  {
    return ret;
  }
  ret = fxls8974cf_read_reg(ctx, FXLS8974CF_ASLP_COUNT_MSB, (uint8_t *)&count_msb, 1);
  if (ret != 0)
  {
    return ret;
  }
  /* Set the ASLP count */
  count_lsb = aslp_config.aslp_cnt_lsb;
  count_msb = aslp_config.aslp_cnt_msb;


  fxls8974cf_mode_set(ctx, STANDBY);
  ret = fxls8974cf_write_reg(ctx, FXLS8974CF_SENS_CONFIG4, (uint8_t *)&sens_config4, 1);
  ret += fxls8974cf_write_reg(ctx, FXLS8974CF_ASLP_COUNT_LSB, (uint8_t *)&count_lsb, 1);
  ret += fxls8974cf_write_reg(ctx, FXLS8974CF_ASLP_COUNT_MSB, (uint8_t *)&count_msb, 1);
  fxls8974cf_mode_set(ctx, ACTIVE);

  return ret;

}

int32_t fxls8974cf_acceleration_raw_get(stmdev_ctx_t *ctx, fxls8974cf_data_t *val)
{
  int32_t ret;
  uint8_t buff[ACCEL_RAW_BYTE];

  ret = fxls8974cf_read_reg(ctx, FXLS8974CF_OUT_X_LSB, buff, ACCEL_RAW_BYTE);
  if (ret != 0)
  {
    return ret;
  }

  if (val == NULL)
  {
    return -1;
  }

  val->x = (int16_t)(((uint16_t)buff[1] << 8) | buff[0]);
  val->y = (int16_t)(((uint16_t)buff[3] << 8) | buff[2]);
  val->z = (int16_t)(((uint16_t)buff[5] << 8) | buff[4]);

  return ret;
}

int32_t fxls8974cf_acceleration_raw_fifo_get(stmdev_ctx_t *ctx,
                                             fxls8974cf_fifo_data_t *val, uint8_t sample_cnt)
{
  int32_t ret;
  uint8_t buff[ACCEL_RAW_BYTE * FIFO_DEPTH];

  ret = fxls8974cf_read_reg(ctx, FXLS8974CF_BUF_X_LSB, buff, (ACCEL_RAW_BYTE * sample_cnt));
  if (ret != 0)
  {
    return ret;
  }

  for (int i = 0; i < sample_cnt; i++)
  {
    val->x[i] = ((int16_t)buff[i * ACCEL_RAW_BYTE + 1] << 8) | buff[i * ACCEL_RAW_BYTE + 0];
    val->y[i] = ((int16_t)buff[i * ACCEL_RAW_BYTE + 3] << 8) | buff[i * ACCEL_RAW_BYTE + 2];
    val->z[i] = ((int16_t)buff[i * ACCEL_RAW_BYTE + 5] << 8) | buff[i * ACCEL_RAW_BYTE + 4];
  }

  return ret;
}

int32_t fxls8974cf_interrupt_status_get(stmdev_ctx_t *ctx,
                                        uint8_t *int_status)
{
  int32_t ret;

  ret = fxls8974cf_read_reg(ctx, FXLS8974CF_INT_STATUS, int_status, 1);

  return ret;
}

int32_t fxls8974cf_sys_mode_get(stmdev_ctx_t *ctx,
                                uint8_t *sys_mode)
{
  int32_t ret;

  ret = fxls8974cf_read_reg(ctx, FXLS8974CF_SYS_MODE, sys_mode, 1);

  return ret;
}

float fxls8974cf_from_raw_to_2g(int16_t lsb)
{
  return (float)(lsb * ACCEL_2G_SENS);
}

float fxls8974cf_from_raw_to_4g(int16_t lsb)
{
  return (float)(lsb * ACCEL_4G_SENS);
}

float fxls8974cf_from_raw_to_8g(int16_t lsb)
{
  return (float)(lsb * ACCEL_8G_SENS);
}

float fxls8974cf_from_raw_to_16g(int16_t lsb)
{
  return (float)(lsb * ACCEL_16G_SENS);
}

/**
  * @}
  *
  */
