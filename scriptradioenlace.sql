Base de datos de almacenes
===========================

CREATE TABLE [dbo].[tab_sto_con] (
	[codvan] [char] (13) NOT NULL ,
	[codcon] [char] (5) NULL ,
	[despre] [varchar] (16) NULL ,
	[codtam] [char] (4) NULL ,
	[codtip] [char] (4) NULL ,
	[estvan] [char] (4) NULL ,
	[tottar] [numeric](18, 0) NULL ,
	[pesmer] [numeric](18, 0) NULL ,
	[codman] [char] (9) NULL ,
	[codubi] [char] (4) NULL ,
	[detubi_1] [char] (8) NULL ,
	[detubi_2] [char] (8) NULL
)
GO

CREATE TABLE [dbo].[genmani] (
	[codman] [char] (9) NOT NULL ,
	[codnav] [char] (5) NULL ,
)
GO

CREATE TABLE [dbo].[tab_nav] (
	[cod_nav] [char] (5) NOT NULL ,
	[des_nav] [varchar] (50) NULL ,
) ON [PRIMARY]
GO

CREATE TABLE [dbo].[tab_sto_mer] (
	[codcom] [varchar] (25) NULL ,
	[codcoh] [varchar] (25) NULL ,
	[coddet] [char] (3) NULL ,
	[totbul] [numeric](18, 3) NULL ,
	[pesmer] [numeric](15, 3) NULL ,
	[codemb] [char] (5) NULL ,
	[codman] [char] (9) NULL ,
	[codubi] [char] (4) NULL ,
	[detubi] [char] (2) NULL ,
}
CREATE TABLE [dbo].[seccarg](
	[codman] [char] (9) NOT NULL ,
	[codcom] [varchar] (25) NOT NULL ,
	[codcoh] [varchar] (25) NOT NULL ,
	[coddet] [char] (3) NOT NULL ,
	[desmar] [varchar] (8000) NULL ,
	[desmer] [varchar] (8000) NULL ,
)

CREATE TABLE [dbo].[tab_sto_veh] (
	[codcom] [varchar] (25) NULL ,
	[codcoh] [varchar] (25) NULL ,
	[coddet] [char] (3) NULL ,
	[totbul] [numeric](8, 0) NULL ,
	[pesmer] [numeric](15, 3) NULL ,
	[codcha] [varchar] (25) NOT NULL ,
	[desveh] [varchar] (50) NULL ,
	[codman] [char] (9) NULL ,
	[codubi] [char] (4) NULL ,
	[detubi] [char] (2) NULL 
)



CREATE TABLE [dbo].[tab_pes_bal_alm] (
	[num_tic] [decimal](8, 0) NOT NULL ,
	[cod_man] [char] (9) NOT NULL ,
	[num_con] [varchar] (25) NULL ,
	[tip_doc] [char] (4) NULL ,
	[num_doc] [char] (10) NULL ,
	[cod_eqp1] [char] (4) NULL ,
	[pes_eqp1] [decimal](8, 0) NULL ,
	[cod_eqp2] [char] (4) NULL ,
	[pes_eqp2] [decimal](8, 0) NULL ,
	[tot_pes] [numeric](15, 3) NULL ,
	[tot_bul] [decimal](8, 0) NULL ,
	[fec_pe1] [datetime] NULL ,
	[cod_ba1] [char] (4) NULL ,
	[cod_emb] [char] (5) NULL ,
	[cod_est] [char] (2) NULL ,
	[des_obs] [varchar] (50) NULL ,
	[fec_reg] [datetime] NULL ,
	[cod_usu] [char] (10) NULL
)

CREATE TABLE [dbo].[tab_det_con_alm] (
	[num_ite] [char] (1) NOT NULL ,
	[cod_man] [char] (9) NULL ,
	[num_tic] [decimal](8, 0) NOT NULL ,
	[codvan] [char] (13) NOT NULL ,
	[codtip] [char] (4) NULL ,
	[num_par] [char] (14) NOT NULL ,
	[codtam] [char] (4) NULL ,
	[tot_tar] [decimal](8, 0) NULL ,
	[tot_pes] [decimal](8, 0) NULL ,
	[fec_reg] [datetime] NULL ,
	[cod_usu] [char] (10) NULL 
)
CREATE TABLE [dbo].[tab_tar_con_des] (
	[codman] [char] (9) NOT NULL ,
	[codcom] [varchar] (25) NOT NULL ,
	[codcoh] [varchar] (25) NOT NULL ,
	[coddet] [char] (3) NOT NULL ,
	[codvan] [char] (13) NOT NULL ,
	[codope] [char] (5) NOT NULL ,
	[tipdoc] [char] (4) NOT NULL ,
	[numdoc] [char] (8) NOT NULL ,
	[tipvan] [char] (4) NULL ,
	[tamvan] [char] (4) NULL ,
	[convan] [char] (5) NULL ,
	[estvan] [char] (4) NULL ,
	[despre] [varchar] (16) NULL ,
	[codubi] [char] (4) NULL ,
	[detubi_1] [char] (8) NULL ,
	[detubi_2] [char] (8) NULL ,
	[tarvan] [numeric](15, 3) NULL ,
	[pesmer] [numeric](15, 3) NULL ,
	[empalm] [char] (4) NULL ,
	[fecingalm] [datetime] NULL ,
	[obser] [varchar] (50) NULL ,
	[fecreg] [datetime] NULL ,
	[codusu] [char] (10) NULL ,
	[sittab] [char] (5) NULL ,
	[tipdocenv] [char] (4) NULL ,
	[numdocenv] [char] (8) NULL ,
	[codonu] [char] (4) NULL ,
	[codlin] [char] (5) NULL ,
	[payload] [numeric](15, 3) NULL ,
	[flatran] [tinyint] NULL ,
	[fladesg] [tinyint] NULL ,
	[flaliq] [char] (1) NULL ,
	[flafac] [tinyint] NULL 
) 
CREATE TABLE [dbo].[tab_pes_bal] (
	[num_tic] [numeric](8, 0) NOT NULL ,
	[cod_man] [char] (9) NULL ,
	[tip_ope] [char] (1) NOT NULL ,
	[cod_ope] [char] (5) NULL ,
	[num_per_des] [char] (10) NULL ,
	[num_per_emb] [char] (10) NULL ,
	[cod_bre] [char] (9) NULL ,
	[num_gui] [numeric](8, 0) NULL ,
	[cod_pla] [char] (8) NULL ,
	[tot_pes] [numeric](15, 3) NULL ,
	[tot_bul] [numeric](8, 0) NULL ,
	[fec_pe1] [datetime] NULL ,
	[cod_ba1] [char] (4) NULL ,
	[fec_pe2] [datetime] NULL ,
	[cod_ba2] [char] (4) NULL ,
	[cod_emb] [char] (5) NULL ,
	[cod_usu] [char] (10) NULL ,
	[cod_est] [char] (2) NULL ,
	[des_obs] [varchar] (50) NULL ,
	[fec_reg] [datetime] NULL ,
	[flag_pes] [char] (1) NULL 
)

CREATE TABLE [dbo].[tab_maes_2] (
	[codigo] [char] (4) NOT NULL ,
	[descripcion] [varchar] (50) NULL ,
)
CREATE TABLE [dbo].[tab_maes_3] (
	[codigo] [char] (5) NOT NULL ,
	[descripcion] [varchar] (50) NULL ,
)

CREATE TABLE [dbo].[tab_equipos] (
	[cod_equ] [char] (4) NOT NULL ,
	[des_equ] [varchar] (30) NULL ,
	[tip_equ] [char] (4) NULL ,
	[cod_pro] [char] (5) NULL ,
	[cod_est] [char] (2) NULL ,
	[num_pla] [char] (8) NULL ,
	[des_mod] [varchar] (30) NULL ,
	[des_mar] [varchar] (30) NULL ,
	[año_fab] [char] (4) NULL ,
	[tot_tar] [decimal](18, 0) NULL ,
	[tot_cap] [decimal](18, 0) NULL ,
	[cod_med] [char] (5) NULL ,
	[tot_rpm] [decimal](18, 0) NULL ,
	[tot_hps] [decimal](18, 0) NULL ,
	[num_ser] [varchar] (15) NULL ,
	[fec_reg] [datetime] NULL ,
	[cod_usu] [char] (10) NULL ,
	[est_equ] [bit] NOT NULL ,
	[codacti] [char] (5) NULL 
)


CREATE TABLE [dbo].[tab_muelle_amar] (
	[cod_mue] [char] (3) NOT NULL ,
	[cod_ama] [char] (3) NOT NULL ,
	[num_bit] [char] (2) NULL ,
	[num_bic] [char] (2) NULL ,
	[num_cor] [char] (2) NULL ,
	[tot_cal] [float] NULL ,
	[tot_lon] [float] NULL ,
	[valor] [char] (3) NULL ,
	[cod_est] [char] (2) NULL ,
	[fec_reg] [datetime] NULL ,
	[cod_usu] [char] (10) NULL 
)

CREATE TABLE [dbo].[tab_man_veh] (
	[cod_pla] [char] (8) NOT NULL ,
	[cod_ca1] [char] (10) NULL ,
	[cod_age] [char] (5) NULL ,
	[tot_ca1] [float] NULL ,
	[tot_ca2] [float] NULL ,
	[des_due] [varchar] (40) NULL ,
	[fec_reg] [datetime] NULL ,
	[cod_ca2] [char] (10) NULL ,
	[cod_usu] [char] (10) NULL ,
	[cod_est] [char] (2) NULL ,
	[mod_veh] [char] (25) NULL ,
	[fec_exp] [datetime] NULL ,
	[nro_eje_tra] [smallint] NULL ,
	[nro_eje_car] [smallint] NULL 
)
CREATE TABLE [dbo].[tab_man_cho] (
	[cod_age] [char] (5) NULL ,
	[cod_bre] [char] (9) NOT NULL ,
	[cod_ide] [char] (4) NULL ,
	[nom_cho] [varchar] (25) NULL ,
	[des_dir] [varchar] (50) NULL ,
	[cod_dis] [char] (5) NULL ,
	[num_ele] [char] (8) NULL ,
	[ape_pat] [varchar] (20) NULL ,
	[ape_mat] [varchar] (20) NULL ,
	[num_mil] [char] (10) NULL ,
	[num_tel] [char] (7) NULL ,
	[fec_ing] [datetime] NULL ,
	[fec_exp] [datetime] NULL ,
	[fec_reg] [datetime] NULL ,
	[cod_est] [char] (2) NULL ,
	[cod_usu] [char] (10) NULL 
)