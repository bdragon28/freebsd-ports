# $FreeBSD: $

COMMENT=	GNU binutils for powerpc64 ELFv2 cross-development
PORTNAME=	binutils
PORTVERSION=	0
USES=	metaport
PKGNAMEPREFIX=  powerpc64-
PKGNAMESUFFIX=	-elfv2
CATEGORIES?=    devel

# powerpc64-binutils
BU_TARGET=	${PKGNAMEPREFIX}unknown-${OPSYS:tl}${OSREL}

RUN_DEPENDS=	${BU_TARGET}-as:devel/${PKGNAMEPREFIX}${PORTNAME}

.include <bsd.port.mk>
