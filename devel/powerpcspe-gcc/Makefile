# $FreeBSD$

PKGNAMEPREFIX=	powerpcspe-
PLIST=	${.CURDIR}/pkg-plist

MASTERDIR=	${.CURDIR}/../powerpc64-gcc
FREEBSD_EXTENSION=	yes
CONFIGURE_ARGS+=	--with-cpu=8540 --enable-e500_double --without-fp --enable-obsolete
#BU_PREFIX=	powerpc-unknown-${OPSYS:tl}${OSREL}

.include "${MASTERDIR}/Makefile"
