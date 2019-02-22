# $FreeBSD$

PKGNAMEPREFIX=		powerpcspe-
PLIST=			${.CURDIR}/pkg-plist

MASTERDIR=		${.CURDIR}/../powerpc64-gcc
FREEBSD_EXTENSION=	yes
CONFIGURE_ARGS+=	--enable-obsolete
BU_PREFIX=		powerpc64-unknown-${OPSYS:tl}${OSREL}
BU_PKGNAMEPREFIX=	powerpc64-

CONFIGURE_ARGS+=        --with-cpu=8548 --enable-e500_double --without-fp

.include "${MASTERDIR}/Makefile"
