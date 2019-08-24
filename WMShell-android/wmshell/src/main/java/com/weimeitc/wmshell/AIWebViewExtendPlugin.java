package com.weimeitc.wmshell;

import android.app.AlertDialog;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.IntentFilter;
import android.util.Log;
import android.webkit.ValueCallback;
import android.webkit.WebView;
import android.widget.Toast;

import com.ai.base.AIBaseActivity;
import com.ai.webplugin.AIWebViewBasePlugin;
import com.anoah.lock.ScreenLocker;

import org.json.JSONArray;
import org.json.JSONObject;

/**
 * author: wuyoujian
 * Date: 2018/12/19
 */
public class AIWebViewExtendPlugin extends AIWebViewBasePlugin {
    private ScreenLocker locker;
    private final static String ACTION_ASR_RESULT_FOR_GAME_COURSE_MODE = "ACTION_ASR_RESULT_FOR_GAME_COURSE_MODE";
    private final static String ACTION_TOUCH_PAD_PRESSED_FOR_GAME_COURSE_MODE ="ACTION_TOUCH_PAD_PRESSED_FOR_GAME_COURSE_MODE";

    public AIWebViewExtendPlugin(AIBaseActivity activity, WebView webView) {
        super(activity,webView);

        locker = new ScreenLocker(activity);

        ASRBroadcastReceiver asrBroadcastReceiver = new ASRBroadcastReceiver();
        //实例化IntentFilter
        IntentFilter intentFilter = new IntentFilter();

        //设置接收广播的类型
        intentFilter.addAction(ACTION_ASR_RESULT_FOR_GAME_COURSE_MODE);
        intentFilter.addAction(ACTION_TOUCH_PAD_PRESSED_FOR_GAME_COURSE_MODE);


        //动态注册
        getActivity().registerReceiver(asrBroadcastReceiver, intentFilter);

    }


    public void JN_QuitApp() {
        System.exit(0);
    }


    public void JN_Unlock() {
        if (locker != null) {
            locker.unlock();
        }
    }



    //继承BroadcastReceiver基类
    public class ASRBroadcastReceiver extends BroadcastReceiver {
        @Override
        public void onReceive(Context context, Intent intent) {
            String action = intent.getAction();
            if (action.contentEquals(ACTION_ASR_RESULT_FOR_GAME_COURSE_MODE)) {
                String asr = intent.getStringExtra("EXTRA_ASR_RESULT");
                try {
                    JSONObject jsonObject = new JSONObject(asr);
                    String text = jsonObject.getString("text");
                    String javascript = "JS_ASR('" + text + "')";
                    excuteJavascript(javascript,null);

                } catch (Exception e) {

                    excuteJavascript("JS_ASR(\"数据异常\")",null);
                }
            } else if (action.contentEquals(ACTION_TOUCH_PAD_PRESSED_FOR_GAME_COURSE_MODE)) {

                String area= intent.getStringExtra("EXTRA_TOUCH_PAD_DETECTED_REGION");
                String javascript = "JS_ASR('" + area + "')";
                excuteJavascript(javascript,null);
            }
        }
    }

    public void JN_AppBroadcast(JSONArray params) {
        try {
            String action="";
            if (params != null &&  params.length() > 0) {
                action = params.getString(0);
            }

            String param = "";
            if (params != null &&  params.length() > 1) {
                param = params.getString(1);
            }

            Intent intent = new Intent();
            intent.setAction(action);
            intent.putExtra("param",param);
            getActivity().sendBroadcast(intent);

        } catch (Exception e) {

        }
    }

    public void JN_QRcode() {
        Intent intent = new Intent();
        intent.setClass(getActivity(), ScanActivity.class);
        intent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
        getActivity().startActivityForResult(this,intent,100);
    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, requestCode,data);
        if (requestCode == 100) {
            if (data != null) {
                String result = data.getStringExtra("result");
                this.callback("JN_QRcode", result, new ValueCallback<String>() {
                    @Override
                    public void onReceiveValue(String value) {

                    }
                });
            }
        }
    }
}
