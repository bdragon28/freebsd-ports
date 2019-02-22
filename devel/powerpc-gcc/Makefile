# $FreeBSD$

PKGNAMEPREFIX=		powerpc-
BU_PKGNAMEPREFIX=	powerpc64-
PLIST=	${.CURDIR}/pkg-plist

MASTERDIR=	${.CURDIR}/../powerpc64-gcc
FREEBSD_EXTENSION=	yes
CONFIGURE_ARGS+=	--with-tune=G4

.include "${MASTERDIR}/Makefile"
