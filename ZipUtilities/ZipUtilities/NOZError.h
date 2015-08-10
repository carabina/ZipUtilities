//
//  NOZError.h
//  ZipUtilities
//
//  The MIT License (MIT)
//
//  Copyright (c) 2015 Nolan O'Brien
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXTERN NSString * const NOZErrorDomain;

typedef NS_ENUM(NSInteger, NOZErrorPage)
{
    NOZErrorPageNone = 0,
    NOZErrorPageCompress,
    NOZErrorPageDecompress,
    NOZErrorPageZip,
    NOZErrorPageUnzip,
};

static const NSInteger NOZErrorPageSize = 100;

typedef NS_ENUM(NSInteger, NOZErrorCode)
{
    NOZErrorCodeCompressUnknown = NOZErrorPageCompress * NOZErrorPageSize,
    NOZErrorCodeCompressFailedToOpenNewZipFile,
    NOZErrorCodeCompressNoEntriesToCompress,
    NOZErrorCodeCompressMissingEntryName,
    NOZErrorCodeCompressMissingEntryDataOrFile,
    NOZErrorCodeCompressFailedToAppendEntryToZip,
    NOZErrorCodeCompressFailedToFinalizeNewZipFile,
    NOZErrorCodeCompressCancelled = NOZErrorPageCompress + NOZErrorPageSize - 1,

    NOZErrorCodeDecompressUnknown = NOZErrorPageDecompress,
    NOZErrorCodeDecompressFailedToOpenZipArchive,
    NOZErrorCodeDecompressFailedToCreateDestinationDirectory,
    NOZErrorCodeDecompressFailedToReadArchiveEntry,
    NOZErrorCodeDecompressFailedToCreateUnarchivedFile,
    NOZErrorCodeDecompressCannotOverwriteExistingFile,
    NOZErrorCodeDecompressCancelled = NOZErrorPageDecompress + NOZErrorPageSize - 1,

    NOZErrorCodeZipUnknown = NOZErrorPageZip,

    NOZErrorCodeUnzipUnknown = NOZErrorPageUnzip,
};

NS_INLINE BOOL NOZErrorCodeIsInErrorPage(NOZErrorCode code, NOZErrorPage page)
{
    return page == (code - (code % NOZErrorPageSize));
}

#define NOZErrorCodeIsCompressError(code)   NOZErrorCodeIsInErrorPage(code, NOZErrorPageCompress)
#define NOZErrorCodeIsDecompressError(code) NOZErrorCodeIsInErrorPage(code, NOZErrorPageDecompress)
#define NOZErrorCodeIsZipError(code)        NOZErrorCodeIsInErrorPage(code, NOZErrorPageZip)
#define NOZErrorCodeIsUnzipError(code)      NOZErrorCodeIsInErrorPage(code, NOZErrorPageUnzip)

#define NOZErrorCreate(errCode, ui) [NSError errorWithDomain:NOZErrorDomain code:(errCode) userInfo:(ui)]

NS_ASSUME_NONNULL_END
