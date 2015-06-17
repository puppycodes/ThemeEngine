//
//  TKGradient.h
//  ThemeKit
//
//  Created by Alexander Zielenski on 6/14/15.
//  Copyright © 2015 Alex Zielenski. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ThemeKit/TKGradientStop.h>

// Specialized gradient class for CoreUI gradients
// that have bonus features
@interface TKGradient : NSObject {
    NSArray<NSNumber *> *_colorMidpoints;
    NSArray<NSNumber *> *_opacityMidpoints;
}
@property (assign, getter=isRadial) BOOL radial;
@property (assign) CGFloat angle;
@property (assign, getter=isDithered) BOOL dithered;
@property (assign) CGFloat smoothingCoefficient;
@property (assign) CGFloat fillCoefficient;
@property (strong) NSColor *fillColor;
@property (assign) CGBlendMode blendMode;

@property (readonly, strong) NSArray<__kindof TKGradientColorStop *> *colorStops;
@property (readonly, strong) NSArray<__kindof TKGradientOpacityStop *> *opacityStops;
@property (nonatomic, strong) NSArray<NSNumber *> *colorMidpoints;
@property (nonatomic, strong) NSArray<NSNumber *> *opacityMidpoints;

+ (instancetype)gradientWithColorStops:(NSArray<__kindof TKGradientColorStop *> *)colorStops
                          opacityStops:(NSArray<__kindof TKGradientOpacityStop *> *)opacityStops
                colorMidPointLocations:(NSArray<NSNumber *> *)colorMidPointLocations
              opacityMidPointLocations:(NSArray<NSNumber *> *)opacityMidPointLocations
                                radial:(BOOL)radial
                                 angle:(CGFloat)angle
                              dithered:(BOOL)dithered;

- (NSColor *)interpolatedColorAtLocation:(CGFloat)location;

- (void)addColorStopsObject:(TKGradientColorStop *)object;
- (void)addColorMidpointsObject:(NSNumber *)object;

- (void)removeColorStopsObject:(TKGradientColorStop *)object;
- (void)removeColorMidpointsObject:(NSNumber *)object;

- (void)addOpacityStopsObject:(TKGradientOpacityStop *)object;
- (void)addOpacityMidpointsObject:(NSNumber *)object;

- (void)removeOpacityStopsObject:(TKGradientOpacityStop *)object;
- (void)removeOpacityMidpointsObject:(NSNumber *)object;

- (void)insertObject:(TKGradientColorStop *)object inColorStopsAtIndex:(NSUInteger)index;
- (void)insertObject:(NSNumber *)object inColorMidpointsAtIndex:(NSUInteger)index;
- (void)insertObject:(TKGradientOpacityStop *)object inOpacityStopsAtIndex:(NSUInteger)index;
- (void)insertObject:(NSNumber *)object inOpacityMidpointsAtIndex:(NSUInteger)index;

- (void)removeObjectFromColorStopsAtIndex:(NSUInteger)index;
- (void)removeObjectFromColorMidpointsAtIndex:(NSUInteger)index;
- (void)removeObjectFromOpacityStopsAtIndex:(NSUInteger)index;
- (void)removeObjectFromOpacityMidpointsAtIndex:(NSUInteger)index;

// The gradient renderer
- (void)resetShaders;

// Radial gradients assume a relative center position in the middle of the rectangle
- (void)drawInRect:(CGRect)rect;
- (void)drawInRect:(CGRect)rect relativeCenterPosition:(CGPoint)relativeCenterPosition;
- (void)drawInRect:(CGRect)rect withContext:(CGContextRef)contex;
- (void)drawInRect:(CGRect)rect relativeCenterPosition:(CGPoint)relativeCenterPosition withContext:(CGContextRef)contex;

@end
