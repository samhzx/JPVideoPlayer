//
//  JPVideoPlayerControlViews.h
//  JPVideoPlayerDemo
//
//  Created by NewPan on 2018/2/20.
//  Copyright © 2018年 NewPan. All rights reserved.
//

#import "JPVideoPlayerProtocol.h"

@class JPVideoPlayerControlProgressView,
       JPVideoPlayerControlView,
       JPVideoPlayerControlProgressView;

NS_ASSUME_NONNULL_BEGIN

@protocol JPVideoPlayerControlProgressViewDelegate<NSObject>

@optional

- (void)progressView:(JPVideoPlayerControlProgressView *)progressView
   userDidDragToTime:(NSTimeInterval)timeInterval
        totalSeconds:(NSTimeInterval)totalSeconds;

@end

UIKIT_EXTERN NSString *JPVideoPlayerControlProgressViewUserDidStartDragNotification;
UIKIT_EXTERN NSString *JPVideoPlayerControlProgressViewUserDidEndDragNotification;
@interface JPVideoPlayerControlProgressView : UIView<JPVideoPlayerProgressProtocol>

@property (nonatomic, weak, nullable) id<JPVideoPlayerControlProgressViewDelegate> delegate;

@property (nonatomic, strong, readonly) NSArray<NSValue *> *rangesValue;

@property(nonatomic, assign, readonly) NSUInteger fileLength;

@property(nonatomic, assign, readonly) NSTimeInterval totalSeconds;

@property(nonatomic, assign, readonly) NSTimeInterval elapsedSeconds;

@property(nonatomic, assign, readonly) BOOL userDragging;

@property (nonatomic, weak, readonly, nullable) UIView *playerView;

@property (nonatomic, strong, readonly) UISlider *dragSlider;

@property (nonatomic, strong, readonly) UIView *cachedProgressView;

@property (nonatomic, strong, readonly) UIProgressView *trackProgressView;

@end

@interface JPVideoPlayerControlBar : UIView<JPVideoPlayerProgressProtocol>

@property (nonatomic, strong, readonly) UIButton *playButton;

@property (nonatomic, strong, readonly) JPVideoPlayerControlProgressView *progressView;

@property (nonatomic, strong, readonly) UILabel *timeLabel;

@property (nonatomic, strong, readonly) UIButton *landscapeButton;

- (instancetype)initWithProgressView:(UIView<JPVideoPlayerProgressProtocol> *_Nullable)progressView NS_DESIGNATED_INITIALIZER;

@end

@interface JPVideoPlayerControlView : UIView<JPVideoPlayerProgressProtocol>

@property (nonatomic, strong, readonly) JPVideoPlayerControlBar *controlBar;

@property (nonatomic, strong, readonly) UIImage *blurImage;

/**
 * A designated initializer.
 *
 * @param controlBar The view abide by the `JPVideoPlayerProgressProtocol`.
 * @param blurImage  A image on back of controlBar.
 *
 * @return The current instance.
 */
- (instancetype)initWithControlBar:(UIView<JPVideoPlayerProgressProtocol> *_Nullable)controlBar
                         blurImage:(UIImage *_Nullable)blurImage NS_DESIGNATED_INITIALIZER;

// TODO: 给外界布局专门一个方法, 抽取协议.
@end

@interface JPVideoPlayerProgressView : UIView<JPVideoPlayerProgressProtocol>

@property (nonatomic, strong, readonly) NSArray<NSValue *> *rangesValue;

@property(nonatomic, assign, readonly) NSUInteger fileLength;

@property(nonatomic, assign, readonly) NSTimeInterval totalSeconds;

@property(nonatomic, assign, readonly) NSTimeInterval elapsedSeconds;

@property (nonatomic, strong, readonly) UIProgressView *trackProgressView;

@property (nonatomic, strong, readonly) UIView *cachedProgressView;

@property (nonatomic, strong, readonly) UIProgressView *elapsedProgressView;

@end

@interface JPVideoPlayerBufferingIndicator : UIView<JPVideoPlayerBufferingProtocol>

@property(nonatomic, strong, readonly)UIActivityIndicatorView *activityIndicator;

@property(nonatomic, strong, readonly)UIVisualEffectView *blurView;

@property(nonatomic, assign, readonly, getter=isAnimating)BOOL animating;

@end

@interface JPVideoPlayerView : UIView

@property (nonatomic, strong, readonly) UIView *videoContainerLayer;

@property (nonatomic, strong, readonly) UIView *controlContainerView;

@property (nonatomic, strong, readonly) UIView *progressContainerView;

@property (nonatomic, strong, readonly) UIView *bufferingIndicatorContainerView;

@property (nonatomic, strong, readonly) UIView *userInteractionContainerView;

@end

NS_ASSUME_NONNULL_END
