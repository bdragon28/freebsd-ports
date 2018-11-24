# $FreeBSD: $
PKGNAMEPREFIX=	powerpc64-
PKGNAMESUFFIX=	-elfv2

# No special binutils requirements.
BU_PREFIX=	${PKGNAMEPREFIX}unknown-${OPSYS:tl}${OSREL}

CONFIGURE_ARGS+= --with-cpu=power6 --with-tune=power9 --with-abi=elfv2

MASTERDIR=	${.CURDIR}/../powerpc64-gcc

.include "${MASTERDIR}/Makefile"
