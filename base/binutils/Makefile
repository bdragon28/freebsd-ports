# $FreeBSD$

PORTEPOCH=	0
CATEGORIES=	base
PKGNAMEPREFIX=	${OPSYS:tl}-
VALID_CATEGORIES=	base

COMMENT=	GNU binary tools for base

MASTERDIR=	${.CURDIR}/../../devel/binutils
PLIST=		${.CURDIR}/pkg-plist

.if defined(CROSS_TOOLCHAIN) && !defined(CROSS_SYSROOT)
.error Please define CROSS_SYSROOT before building
.elif !defined(CROSS_TOOLCHAIN)
CROSS_SYSROOT?=	/
# We are doing a true native build.
# Since some of our tools are not prefixed, override autodetection.
AR?=		/usr/bin/ar
NM?=		/usr/bin/nm
STRIPBIN?=	/usr/bin/strip
CONFIGURE_ENV+=	AR=${AR} \
		NM=${NM} \
		CC_FOR_BUILD=${CC} \
		STRIPBIN=${STRIPBIN}
.endif

TARGETARCH=	${ARCH:S/amd64/x86_64/:S/powerpcspe/e500v2/}
BUTARGET=	${TARGETARCH}-unknown-${OPSYS:tl}${OSREL}

CONFIGURE_ARGS+=	--disable-host-shared \
			--host=${BUTARGET}

BINUTILS_BUILDING_BASE=

PREFIX=	/usr
BUREMOVE=	addr2line \
		ar \
		c++filt \
		dlltool \
		elfedit \
		gprof \
		nlmconv \
		nm \
		ranlib \
		readelf \
		size \
		strings \
		strip \
		windmc \
		windres

.include "${MASTERDIR}/Makefile"

PLIST_SUB+=	OBJCOPY="@comment "
BUREMOVE+=	objcopy

.if ${ARCH} == "amd64" || ${ARCH} == "i386"
PLIST_SUB+=	I386=""
.else
PLIST_SUB+=	I386="@comment "
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
PLIST_SUB+=	POWERPC=""
. if ${ARCH:Mpowerpcspe*}
PLIST_SUB+=	POWERPC64="@comment "
. else
PLIST_SUB+=	POWERPC64=""
. endif
.else
PLIST_SUB+=	POWERPC="@comment "
PLIST_SUB+=	POWERPC64="@comment "
.endif
.if ${ARCH:Msparc*}
PLIST_SUB+=	SPARC=""
.else
PLIST_SUB+=	SPARC="@comment "
.endif
