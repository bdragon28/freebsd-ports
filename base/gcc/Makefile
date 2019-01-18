# $FreeBSD: head/base/gcc/Makefile 475401 2018-07-26 22:25:19Z jhb $

PORTNAME=	gcc
PORTVERSION=	8.2.0
PORTREVISION=	1
CATEGORIES=	base
MASTER_SITES=	GCC/releases/gcc-${DISTVERSION} \
		http://www.mpfr.org/mpfr-current/:mpfr \
		GNU/gmp:gmp \
		https://ftp.gnu.org/gnu/mpc/:mpc
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		mpfr-4.0.1/mpfr-4.0.1.tar.xz:mpfr \
		gmp-6.1.2.tar.xz:gmp \
		mpc-1.1.0.tar.gz:mpc
PKGNAMEPREFIX=	${OPSYS:tl}-

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	GNU Compiler Collection

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

.if defined(CROSS_TOOLCHAIN) && !defined(CROSS_SYSROOT)
.error Please define CROSS_SYSROOT before building
.endif

TARGETARCH=	${ARCH:S/amd64/x86_64/:S/powerpcspe/e500v2/}
GCC_TARGET=	${TARGETARCH}-unknown-${OPSYS:tl}${OSREL}

PREFIX=		/usr
CONFIGURE_ENV=	NM=/usr/bin/nm \
		AS_FOR_TARGET=/usr/bin/as \
		LD_FOR_TARGET=/usr/bin/ld \
		NM_FOR_TARGET=/usr/bin/nm
USES=	gmake libtool tar:xz makeinfo
PLIST_SUB=	TARGETARCH=${TARGETARCH} \
		OPSYS=${OPSYS:tl} \
		GCC_TARGET=${GCC_TARGET} \
		GCC_VERSION=${PORTVERSION}

EXTRA_PATCHES+= ${.CURDIR}/../../devel/powerpc64-gcc/files/freebsd-format-extensions
EXTRA_PATCHES+= ${.CURDIR}/../../devel/powerpc64-gcc/files/patch-fuse-ld=lld
EXTRA_PATCHES+= ${.CURDIR}/../../devel/powerpc64-gcc/files/patch-gcc-freebsd-mips
EXTRA_PATCHES+= ${.CURDIR}/../../devel/powerpc64-gcc/files/patch-gets-no-more
EXTRA_PATCHES+= ${.CURDIR}/../../devel/powerpc64-gcc/files/patch-spe-config

MPFR_PATCHLEVEL=	13
MPFR_PATCHFILES!=	/usr/bin/jot -s " " -w mpfr-4.0.1/patch%02d ${MPFR_PATCHLEVEL} 1 ${MPFR_PATCHLEVEL}

PATCHFILES+= ${MPFR_PATCHFILES}

GNU_CONFIGURE=	yes
CONFIGURE_OUTSOURCE=	yes
CONFIGURE_ARGS+=	\
		--with-sysroot=/ \
		--host=${GCC_TARGET} \
		--target=${GCC_TARGET} \
		--enable-languages=c,c++ \
		--enable-gnu-indirect-function \
		--disable-nls \
		--without-headers \
		--with-gxx-include-dir=/usr/include/c++/v1/ \
		--with-build-sysroot=${CROSS_SYSROOT} \
		-with-pkgversion="GNU Collection for FreeBSD"

ALL_TARGET?=	all-gcc
INSTALL_TARGET?=	install-gcc

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 1200000
CONFIGURE_ARGS+= --enable-initfini-array
.endif

.if ${ARCH} == "amd64" || ${ARCH} == "i386"
PLIST_SUB+=	I386="" \
		FLOAT_H="@comment "
.else
PLIST_SUB+=	I386="@comment " \
		FLOAT_H=""
.endif
.if ${ARCH} == "amd64"
PLIST_SUB+=	AMD64=""
.else
PLIST_SUB+=	AMD64="@comment "
.endif
.if ${ARCH:Mmips*}
PLIST_SUB+=	MIPS=""
.else
PLIST_SUB+=	MIPS="@comment "
.endif
.if ${ARCH:Mpowerpc*}
PLIST_SUB+=     POWERPC=""
. if ${ARCH} == "powerpcspe"
PLIST_SUB+=     POWERPC64="@comment "
PLIST_SUB+=	POWERPC_NON_SPE="@comment "
PLIST_SUB+=	POWERPCSPE=""
. elif ${ARCH} == "powerpc"
PLIST_SUB+=     POWERPC64="@comment "
PLIST_SUB+=	POWERPC_NON_SPE=""
PLIST_SUB+=	POWERPCSPE="@comment "
. else
PLIST_SUB+=     POWERPC64=""
PLIST_SUB+=	POWERPC_NON_SPE=""
PLIST_SUB+=	POWERPCSPE="@comment "
. endif
.else
PLIST_SUB+=     POWERPC="@comment "
PLIST_SUB+=     POWERPC64="@comment "
PLIST_SUB+=	POWERPC_NON_SPE="@comment "
PLIST_SUB+=	POWERPCSPE="@comment "
.endif

.if ${ARCH:Mpowerpc64*}
CONFIGURE_ARGS+=	--with-cpu=powerpc64 --with-tune=power9 --with-abi=elfv2
.endif

# Note: the mpfr-4.0.1-b symlink is used so that mpfr patches can be
# applied to the wrong work directory.
post-extract:
	cd ${WRKSRC}; ${LN} -sf ../mpfr-4.0.1 mpfr ; \
		${LN} -sf ../mpfr-4.0.1 mpfr-4.0.1-b ; \
		${LN} -sf ../gmp-6.1.2 gmp ; \
		${LN} -sf ../mpc-1.1.0 mpc

post-patch:
	@${REINPLACE_CMD} -e '/LIBSTDCXX/ s/stdc\+\+/c\+\+/g ' \
		${WRKSRC}//gcc/cp/g++spec.c
	@${REINPLACE_CMD} -e '/LOCAL_INCLUDE_DIR/ d ' \
		${WRKSRC}//gcc/Makefile.in

post-install:
	${MV} -f ${STAGEDIR}/usr/bin/gcov-tool ${STAGEDIR}/usr/bin/${GCC_TARGET}-gcov-tool ; \
	for tool in cpp gcc g++ gcov; do \
		${MV} -f ${STAGEDIR}/usr/bin/$${tool} ${STAGEDIR}/usr/bin/${GCC_TARGET}-$${tool} ; \
		${LN} -sf ${GCC_TARGET}-$${tool}  ${STAGEDIR}/usr/bin/$${tool} ; \
		${MV} -f ${STAGEDIR}/${MANDIR}1/$${tool}.1 ${STAGEDIR}/${MANDIR}1/${GCC_TARGET}-$${tool}.1 ; \
		${GZIP_CMD} ${STAGEDIR}/${MANDIR}1/${GCC_TARGET}-$${tool}.1 ; \
		${LN} -sf ${GCC_TARGET}-$${tool}.1.gz ${STAGEDIR}/${MANDIR}1/$${tool}.1.gz ; \
	done ; \
	${LN} -sf ${GCC_TARGET}-g++  ${STAGEDIR}/usr/bin/c++ ; \
	${LN} -sf ${GCC_TARGET}-g++.1.gz ${STAGEDIR}/${MANDIR}1/c++.1.gz
	${LN} -sf ${GCC_TARGET}-gcc  ${STAGEDIR}/usr/bin/cc ; \
	${LN} -sf ${GCC_TARGET}-gcc.1.gz ${STAGEDIR}/${MANDIR}1/cc.1.gz
	${RM} -r ${STAGEDIR}/usr/share/info
	${RM} -r ${STAGEDIR}/usr/lib/gcc/${GCC_TARGET}/${PORTVERSION}/include-fixed
.if ${ARCH} == "amd64" || ${ARCH} == "i386"
	${RM} ${STAGEDIR}/usr/lib/gcc/${GCC_TARGET}/${PORTVERSION}/include/float.h
.endif

.include <bsd.port.mk>
